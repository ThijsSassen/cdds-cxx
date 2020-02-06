Examples                                                                        {#isocpp_examples}
========

[TOC]

DCPS Examples                                                                   {#isocpp_examples_dcpslist}
=============

The examples source code can be found in the examples folder of your CXX installation.
The descriptions below summarize what each example demonstrates. Towards the bottom of
the page you will find instructions on how to build and run the examples.

helloworld                                                                              {#hello}
----------
- This is a simple publisher and subscriber example. One sample is published, the
sample is then read. Some non-default QoS are used to guarantee delivery and to
allow the publisher to be optionally run before the subscriber.


Description
-----------
The basic hello example is used to illustrate the necessary
steps to setup DCPS entities.


Design
------

It consists of 2 executables:

+ publisher :  Creates a DataWriter from publisher to send a message

+ subscriber : Creates a DataReader from subscriber to receive a message


Scenario
--------
The publisher sends a single Hello World sample.
The sample contains 2 fields :

+ a userID key field (long type)
+ a message field (string type).

When the subscriber receives the sample, it displays the userID field and the message field.

Build:
------
To build the example simply do

    cd share/CycloneDDS_CXX_API/examples/helloworld
    mkdir build
    cd build
    cmake -DCMAKE_PREFIX_PATH="<idlpp-cxx install path>/lib/cmake/Idlpp-cxx;<CycloneDDS install path>/lib/cmake/CycloneDDS" ..
    cmake --build .

Running the example:
--------------------

Most of our examples are provided in publisher and subscriber form. They
reside in their respective folder within each example directory. It is
recommended that you start these from different terminals and the working
directory must be writeable.

This example does not require any options to run.