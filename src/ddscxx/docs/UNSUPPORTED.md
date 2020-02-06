Unsupported Classes and Functions                                                                   {#unsupported_classes_and_functions}
---------------------------------

Unsupported Classes                                                                                 {#unsupported_classes}
===================

The following classes are currently unsupported in the ISO C++ API:

- dds::topic
    - dds::topic::ContentFilteredTopic
- dds::pub
    - dds::pub::CoherentSet
    - dds::pub::SuspendedPublication
- dds::sub
    - dds::sub::Query
    - dds::sub::cond::QueryCondition
    - dds::sub::CoherentAccess
- dds::core::policy::UserData, dds::core::policy::GroupData, dds::core::policy::TopicData
    - The above policy classes are only partially supported. For each class, the constructor that
    takes either two pointers or two iterators is not currently supported, nor are the begin or end
    functions if present.

Unsupported Functions                                                                               {#unsupported_functions}
=====================

The following functions are currently unsupported in the Lite ISO C++ API:

- dds::core
    - dds::core::Entity
        - dds::core::Entity::retain
        - dds::core::Entity::instance_handle
- dds::domain
    - dds::domain::DomainParticipant
        - dds::domain::DomainParticipant::assert_liveliness
        - dds::domain::DomainParticipant::lookup_topics
        - dds::domain::DomainParticipant::contains_entity
    - org::eclipse::cyclonedds::domain::default_id is not supported by dds::domain::find
- dds::topic
    - dds::topic::discover_topics
    - dds::topic::ignore
- dds::pub
    - dds::pub::ignore
    - dds::pub::matched_subscriptions
    - dds::pub::matched_subscription_data
    - dds::pub::Publisher
        - dds::pub::Publisher::wait_for_acknowledgments
    - dds::pub::DataWriter
        - dds::pub::DataWriter::unregister_instance
        - dds::pub::DataWriter::assert_liveliness
        - dds::pub::DataWriter::wait_for_acknowledgments
- dds::sub
    - dds::sub::ignore
    - dds::sub::builtin_subscriber
    - dds::sub::matched_publications
    - dds::sub::matched_publication_data
    - dds::sub::find<typename READER, typename FwdIterator>(const dds::sub::Subscriber&, const dds::sub::status::DataState&, FwdIterator, uint32_t)
    - dds::sub::find<typename READER, typename BinIterator>(const dds::sub::Subscriber&, const dds::sub::status::DataState&, BinIterator)
    - dds::sub::Subscriber
        - dds::sub::Subscriber::get_datareaders
    - dds::sub::DataReader
        - dds::sub::DataReader::Selector::next_instance
        - dds::sub::DataReader::Selector::filter_content
