ISO/IEC C++ DCPS API                                                            {#mainpage}
====================

[TOC]

ISO C++ is the latest DDS DCPS API for the C++ Language. It is more user friendly
and simpler to use.

As of Vortex Lite version 2.0 the only supported ISO C++ version is v2. While most things
haven't changed between ISOC++ V1 and V2 regarding the API, there are still some differences
that should be considered when migrating from V1 to V2. These differences are addressed in
the \subpage migrationguide.

This documentation serves to provide a reference guide and a basic introduction to
the ISO C++ API. Due to the way that ISO C++ is implemented using delegates, the
API reference is not a 1:1 representation of the implementation structure of the API,
it is however a representation of the user accessible layer of the API.

A number of classes and functions are not currently supported in the Lite ISO C++ API.
Details of these can be found on the \subpage unsupported_classes_and_functions page.

Getting started                                                                {#mainpage_gettingstarted}
===============

If you are new to ISO C++ we would recommend that you start by looking at the example
code provided in your Lite installation directory as well as the documentation
in the sections below.

A summary of each example, along with build instructions can be found on the
\subpage isocpp_examples page.

The OMG ISO C++ specification also gives an overview of the general design of ISO C++ and
can be found at the following link: http://www.omg.org/spec/DDS-PSM-Cxx/

How to use ISO C++ classes                                                      {#mainpage_howtouse}
--------------------------

ISO C++ was designed in such a way that all memory management is handled automatically
for you. Class instances should be created on the stack rather than the heap and the API itself
will handle the allocation and deletion of memory automatically.

There are two main types of class within ISO C++, Value and Entity. All classes within
ISO C++ inherit from one of these two classes.

Value classes are the simplest type of class within ISO C++. These are simple classes which
are created on the stack and are copied by value. Examples of this type of class include QoS policies
such as dds::core::policy::Durability and dds::core::policy::Liveliness or status conditions
such as dds::core::status::LivelinessChangedStatus.

Entity classes on the other hand are more advanced but still easy to use. These contain an
underlying smart pointer which keeps track of the number of references that exist to that
particular instance of the class. Once there are no remaining references to the class instance, any
memory used by it is then automatically deleted. This underlying smart pointer brings with it
the advantage of low overhead copying of class instances as only the smart pointer needs to be copied.
This means that any number of references may point to the same entity class instance.

Below is an example of how a dds::domain::DomainParticipant can be created and copied, other
Entity classes work in the same way.

    {
        dds::domain::DomainParticipant dp1(dds::core::null); //dds::core::null creates an uninitialised Entity
        {
            dds::domain::DomainParticipant dp2(0); //Creates a domain participant on domain 0

            dp1 = dp2; //Copies reference to dp2 into dp1, both references now point to the same class instance
        }
        //dp2 is now out of scope but the domain participant is not deleted as dp1 still has a reference to it
    }
    //dp1 is now out of scope and there are no further references to the domain participant so it is deleted automatically

More ISO C++ code examples can be found on the \subpage snippets page.

API documentation                                                               {#mainpage_api}
-----------------

The namespaces below contain all of the major functionality of the ISO C++ API:

- ::dds

   + dds::domain
    + The dds::domain namespace provides facilities for creating a DomainParticipant
      that establishes a virtual network in which an application and it's entities
      can operate.
   + dds::topic
    + The dds::topic namespace provides facilities for the creation of Topics which
      can be published or subscribed to.
   + dds::pub
    + The dds::pub namespace provides facilities for writing samples based on a Topic.
   + dds::sub
    + The dds::sub namespace provides facilities for reading samples based on a Topic.
   + dds::core
    + The dds::core namespace provides core facilities such as QoS policies and the
      ability to wait on particular conditions using a WaitSet.
