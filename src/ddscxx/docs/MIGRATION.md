ISO C++ V2 Migration Guide {#migrationguide}
==========================

As of Vortex Lite version 2.0 the only supported ISO C++ version is V2. Most code written for
ISO C++ V1 will still compile and run but there may be some minor changes required. As well as
this, ISO C++ V2 introduces a number of improvements over V1 which are detailed in the following
document.

Rationale {#migrationguide_rationale}
=========

While most things haven't changed between ISO C++ V1 and V2 regarding the API, there were a few
issues with ISO C++ V1 that needed to be addressed.

- The first iteration of the ISO C++ Specification contains a few issues.
    - ISO C++ V2 has been created to address these issues and as an advance of the new ISO C++
      Specification that will be released.
    - **An application that uses ISO C++ V2 will be more future proof.**
- The ISO C++ V1 API is build on top of the Classic C++ API.
    - To improve performance and reduce maintenance costs, it was decided to remove the dependency
      of the Classic C++ API and thus remove an extra layer within the implementation.
    - **An application that uses ISO C++ V2 will have increased performance and a lower footprint.**
- The ISO C++ V1 API is missing a few features.
    - The features that are present in V2 but not in V1 are mainly (but not limited to):
        - Most listeners, like PublisherListener and DomainParticipantListener.
        - Google protocol buffers support.
    - **An application that uses ISO C++ V2 will have a more complete feature set.**

API Changes {#migrationguide_api_changes}
===========

- Down-casting within an entity class hierarchy has improved.
    - Up and down-casting can be done by constructors and assignment operators.
    - An invalid cast will trigger the dds::core::IllegalOperationError exception.

            dds::domain::DomainParticipant dp(0);
            dds::pub::Publisher pub(dp);
            dds::core::Entity en(pub);       /* Up-cast */

            dds::pub::Publisher pub1(en);    /* Down-cast by constructor. */
            dds::pub::Publisher pub2(dds::core::null);
            pub2 = en;                       /* Down-cast by assignment.  */

            dds::sub::Subscriber sub1(en);   /* This throws an exception (can not cast pub to sub). */
            dds::sub::Subscriber sub2(dds::core::null);
            sub2 = en;                       /* This throws an exception (can not cast pub to sub). */

    - During the conversions, new temporary objects (aka rvalues) are created. This has some
      restrictions because you can't assign a rvalue to an non-const reference:

            using dds::core::cond;

            void func(GuardCondition  gc) { }
            void func_ref(GuardCondition& gc) { }
            void func_cref(const GuardCondition& gc) { }

            /* GuardCondition <-> Condition conversion is used to illustrate the restriction,
            * but this principle is applicable for all conversions. */
            GuardCondition gc1;

            Condition cond(gc1);                 /* rvalue assigned to lvalue immediately:  OK            */
            GuardCondition gc2(cond);            /* rvalue assigned to lvalue immediately:  OK            */
            const GuardCondition &gc3(cond);     /* rvalue assigned to const reference:     OK            */
            GuardCondition &gc4(cond);           /* rvalue assigned to non-const reference: Compile Error */

            func(cond);        /* rvalue assigned to lvalue function argument immediately:  OK            */
            func_cref(cond);   /* rvalue assigned to const reference function argument:     OK            */
            func_ref(cond);    /* rvalue assigned to non-const reference function argument: Compile Error */
            func_ref(gc1);                       /* no conversion, no rvalue to assign:     OK            */

- Some class hierarchies have changed.
    - The AnyDataReader is now a parent class of DataReader<T>.
    - The AnyDataWriter is now a parent class of DataWriter<T>.
    - The AnyTopic is now a parent class of Topic<T>.
        - The function get() was used to convert an Any* entity into a typed entity. Now the
          conversion can be done by the new casting system.

                dds::sub::DataReader<Foo::Bar> reader(subscriber);
                dds::sub::AnyDataReader any(reader);        /* Up-cast   */
                dds::sub::DataReader<Foo::Bar> rdr1(any);   /* Down-cast */
                dds::sub::DataReader<Foo::Qux> rdr2(any);   /* Exception */

- The TopicDescription class is now typeless.
    - Because the TopicDescription is typeless, it replaces the AnyTopicDescription functionality.
      AnyTopicDescription is therefore deleted.

- The Query and QueryCondition classes have some changes.
    - The QueryCondition now inherits from Query. This enables the use of the QueryCondition as a
      content filter which can be applied to a Selector associated with a DataReader.
    - The Query inherits from Reference instead of Value. This implies that the copy semantics
      have changed (shallow copy instead of deep copy). This affects the behavior of the Query
      when used as content filter of a DataReader::Selector. When a query is applied to a Selector
      and for example the Query parameters are changed then these changes will also be applied to
      the associated Selector.
    - Currently the state of the Query may change when the Query is used with a Selector and on
      this Selector a state filter is applied. In that case the state filter applied on the Selector
      will also be applied to the associated Query. This does not apply when a QueryCondition is
      used as a content filter of a Selector. Thus the setting of the Selector's state filter will
      not affect the state of the QueryCondition associated with that Selector.

- The Functors that you may apply to the Condition class no longer expect typeless operations.
    - Each functor operation now expects 1 parameter of type dds:core::cond::Condition&.
    - You can also specify functor operations that expect a parameter of a subclass of Condition
      (e.g. const dds::sub::cond::ReadCondition&).
        - In that case one of the above-mentioned implicit upcast constructors will be invoked.
        - If the functor operation that you specify expects a certain subclass of Condition that
          does not match the type of Condition that is passed, an IllegalOperationError will be thrown.
    - When using a subclass as functor parameter, an implicit conversion needs to happen. This means
      that the parameter of the functor has the same restrictions as mentioned in the Conversions
      paragraph: a functor with a non-const subclass reference will not compile. The GuardCondition
      subclass is used as example, but the restriction is applicable for all Condition subclasses.

            /*
            * Compilable GuardCondition functors
            */
            class FunctorGuardConditionConst {
            public:
                void operator ()(const dds::core::cond::GuardCondition& condition) {
                    /* condition not modifiable */
                }
            };
            class FunctorGuardConditionNonConst {
            public:
                void operator ()(dds::core::cond::GuardCondition condition) {
                    /* condition modifiable (not a reference) */
                }
            };
            class FunctorCondition {
            public:
                void operator ()(dds::core::cond::Condition& condition) {
                    /* Notice the non-const Condition reference.
                    * This doesn't need a conversion, so no rvalue is created.
                    * The cast has to be done explicitly, when needed. */
                }
            };

            /*
            * NOT Compilable GuardCondition functor
            */
            class FunctorGuardConditionFail {
            public:
                void operator ()(dds::core::cond::GuardCondition& condition) {
                    /* Notice the non-const GuardCondition reference... */
                }
            };

- The StatusCondition is now a singleton.
    - That means that if I instantiate multiple StatusConditions for the same Entity, they will all
      refer to the same StatusCondition.
    - This allows for patterns where I can create a StatusCondition, pass a functor to it, and then
      create another reference to the StatusCondition based on an AnyReader that is typeless. Since
      both StatusConditions originate from the same Entity, they will both share the same functor.
        - This, and the fact that functors now always receive the Condition that has triggered,
          allows for a nice way to dispatch to the functors you prepared for your typed Readers:
          see the code block below.

                // Create participant and coherent Subscriber.
                dds::domain::DomainParticipant dp(0);
                dds::sub::qos::SubscriberQos subQos = dp.default_subscriber_qos();
                subQos << dds::core::policy::Presentation::GroupAccessScope(true, false); // coherent = true, ordered = false.
                dds::sub::Subscriber mySub(dp, subQos);
                dds::core::cond::WaitSet myWS();

                // Create the topics
                dds::topic::Topic<Space::Type1> myTopic1(dp, "Topic1");
                dds::topic::Topic<Space::Type2> myTopic2(dp, "Topic2");
                ....

                // Create unique functors for each topic.
                class Reader1SCFunctor {
                public:
                    void operator ()(const dds::core::cond::StatusCondition &cond) {
                        dds::sub::DataReader<Space::Type1> dr(cond.entity());
                        dds::sub::LoanedSamples<Space::Type1> samples = dr.take();
                    }
                }
                ....

                // Create the Readers and pass a unique Functor to their StatusConditions.
                dds::sub::DataReader<Space::Type1> reader1(sub, myTopic1);
                dds::core::cond::StatusCondition statusCond1(reader1, myReader1SCFunctor);
                myWS.attach_condition(statusCond1);
                dds::sub::DataReader<Space::Type1> reader2(sub, myTopic2);
                dds::core::cond::StatusCondition statusCond2(reader2, myReaderSC2Functor);
                myWS.attach_condition(statusCond2);
                ...

                while (true)
                {
                    std::vector<dds::sub::AnyDataReader> readerList;
                    dds::sub::status::DataState notReadState(dds::sub::status::SampleState::not_read());

                    myWS.wait(dds::core::Duration::infinite());

                    dds::sub::CoherentAccess coherentScope(mySub);
                    uint32_t nrReaders = dds::sub::find<dds::sub::AnyDataReader>(
                                    mySub, notReadState, std::back_inserter<std::vector<dds::sub::AnyDataReader> >(readerList), MAX_READERS);
                    for (uint32_t i = 0; i < nrReaders; i++) {
                        dds::core::cond::StatusCondition sc(readerList[i]);
                        sc.dispatch();
                    }
                    coherentScope.end(); // Moved into the while loop. Can be removed too, since the destructor will otherwise end the set.
                }

- The following function

        template <typename ANYTOPIC, typename BinIterator>dds::topic::discover(const dds::domain::DomainParticipant& dp, BinIterator begin);

    has been renamed to

        template <typename ANYTOPIC, typename BinIterator>dds::topic::discover_all(const dds::domain::DomainParticipant& dp, BinIterator begin)

    Reason for this is that the old name clashed with

        template <typename TOPIC>
        TOPIC discover(const dds::domain::DomainParticipant& dp,
                    const std::string& name,
                    const dds::core::Duration& timeout = dds::core::Duration::infinite());

    when invoked with just 2 parameters. Instead of substituting the 3rd parameter, the compiler
    would in that case interpret the std::string as the BinIterator and invoke that function instead.
- This is because overloaded functions are first matched on the amount of parameters, and only when
  there is no match it will look for possibilities to add default parameters. In this particular
  case a match with 2 parameters is possible by using std::string as the template parameter for the
  BinIterator.
