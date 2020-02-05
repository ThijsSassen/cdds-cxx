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

using namespace org::eclipse::cyclonedds;

int main(int, char**) {
    int result = EXIT_SUCCESS;

    try {
        std::cout << "=== [Publisher] Create writer." << std::endl;

        /* First, a domain participant is needed.
         * Create one on the default domain. */
        dds::domain::DomainParticipant participant(domain::default_id());

        /* To publish something, a topic is needed. */
        dds::topic::Topic<HelloWorldData::Msg> topic(participant, "ddscxx_helloworld_example");

        /* A writer also needs a publisher. */
        dds::pub::Publisher publisher(participant);

        /* Now, the writer can be created to publish a HelloWorld message. */
        dds::pub::DataWriter<HelloWorldData::Msg> writer(publisher, topic);

        /* For this example, we'd like to have a subscriber to actually read
         * our message. This is not always necessary. Also, the way it is
         * done here is just to illustrate the easiest way to do so. It isn't
         * really recommended to do a wait in a polling loop, however.
         * Please take a look at Listeners and WaitSets for much better
         * solutions, albeit somewhat more elaborate ones. */
        std::cout << "=== [Publisher] Waiting for subscriber." << std::endl;
        while (writer.publication_matched_status().current_count() == 0) {
            Sleep(20 /*msec*/);
        }

        /* Create a message to write. */
        HelloWorldData::Msg msg(1, "Hello World");

        /* Write the message. */
        std::cout << "=== [Publisher] Write sample." << std::endl;
        writer.write(msg);

        /* With a normal configuration (see dds::pub::qos::DataWriterQos
         * for various different writer configurations), deleting a writer will
         * dispose all its related message.
         * Wait for the subscriber to have stopped to be sure it received the
         * message. Again, not normally necessary and not recommended to do
         * this in a polling loop. */
        std::cout << "=== [Publisher] Waiting for sample to be accepted." << std::endl;
        while (writer.publication_matched_status().current_count() > 0)
        {
            Sleep(20 /*msec*/);
        }
    }
    catch (const dds::core::Exception& e) {
        std::cerr << "=== [Publisher] Exception: " << e.what() << std::endl;
        result = EXIT_FAILURE;
    }

    std::cout << "=== [Publisher] Done." << std::endl;

    return result;
}
