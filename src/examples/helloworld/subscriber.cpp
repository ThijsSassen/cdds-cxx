#include <stdio.h>
#include <stdlib.h>

#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif


/* Include the C++ DDS API. */
#include "dds/dds.hpp"

/* Include data type and specific traits to be used with the C++ DDS API. */
#include "HelloWorldData_DCPS.hpp"


int main ()
{
    int result = EXIT_SUCCESS;

    dds::domain::DomainParticipant participant = dds::core::null;
    dds::topic::Topic<HelloWorldData::Msg> topic = dds::core::null;
    dds::sub::Subscriber subscriber = dds::core::null;
    dds::sub::DataReader<HelloWorldData::Msg> reader = dds::core::null;

    try
    {
        std::cout << "=== [Subscriber] Create reader." << std::endl;

        /* First, a domain participant is needed.
         * Create one on the default domain. */
        participant = dds::domain::DomainParticipant(org::eclipse::cyclonedds::domain::default_id());

        /* To subscribe to something, a topic is needed. */
        topic = dds::topic::Topic<HelloWorldData::Msg>(participant, "ddscxx_helloworld_example");

        /* A reader also needs a subscriber. */
        subscriber = dds::sub::Subscriber(participant);

        /* Now, the reader can be created to subscribe to a HelloWorld message. */
        reader = dds::sub::DataReader<HelloWorldData::Msg>(subscriber, topic);

        /* Poll until a message has been read.
         * It isn't really recommended to do this kind wait in a polling loop.
         * It's done here just to illustrate the easiest way to get data.
         * Please take a look at Listeners and WaitSets for much better
         * solutions, albeit somewhat more elaborate ones. */
        std::cout << "=== [Subscriber] Wait for message." << std::endl;
        bool poll = true;
        while (poll)
        {
            /* For this example, the reader will return a set of messages (aka
             * Samples). There are other ways of getting samples from reader.
             * See the various read() and take() functions that are present. */
            dds::sub::LoanedSamples<HelloWorldData::Msg> samples;

            /* Try taking samples from the reader. */
            samples = reader.take();

            /* Are samples read? */
            if (samples.length() > 0)
            {
                /* Use an iterator to run over the set of samples. */
                dds::sub::LoanedSamples<HelloWorldData::Msg>::const_iterator sample_iter;
                for (sample_iter = samples.begin();
                     sample_iter < samples.end();
                     ++sample_iter)
                {
                    /* Get the message and sample information. */
                    const HelloWorldData::Msg& msg = sample_iter->data();
                    const dds::sub::SampleInfo& info = sample_iter->info();

                    /* Sometimes a sample is read, only to indicate a data
                     * state change (which can be found in the info). If
                     * that's the case, only the key value of the sample
                     * is set. The other data parts are not.
                     * Check if this sample has valid data. */
                    if (info.valid())
                    {
                        std::cout << "=== [Subscriber] Message received:" << std::endl;
                        std::cout << "    userID  : " << msg.userID() << std::endl;
                        std::cout << "    Message : \"" << msg.message() << "\"" << std::endl;

                        /* Only 1 message is expected in this example. */
                        poll = false;
                    }
                }
            }
            else
            {
                Sleep(50 /*msec*/);
            }
        }
    }
    catch (const dds::core::Exception& e)
    {
        std::cerr << "=== [Subscriber] Exception: " << e.what() << std::endl;
        result = EXIT_FAILURE;
    }

    std::cout << "=== [Subscriber] Done." << std::endl;

    return result;
}
