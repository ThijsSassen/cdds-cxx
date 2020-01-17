/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2015 PrismTech
*   Limited and its licensees. All rights reserved. See file:
*
*                     $LITE_HOME/LICENSE
*
*   for full copyright notice and license terms.
*
*/


/**
 * @file
 */

#ifndef LITE_FORWARD_DECLARATIONS_HPP_
#define LITE_FORWARD_DECLARATIONS_HPP_

namespace dds
{
    namespace domain
    {
        class DomainParticipantListener;

        template <typename DELEGATE>
        class TDomainParticipant;
    }

    namespace sub
    {
        template <typename T, template <typename Q> class DELEGATE>
        class DataReader;

        template <typename T>
        class DataReaderListener;

        class SubscriberListener;

        template <typename DELEGATE>
        class TSubscriber;

        namespace detail
        {
            template <typename T>
                class DataReader;

            template <typename T>
                class LoanedSamplesHolder;

            template <typename T, typename SamplesFWIterator>
                class SamplesFWInteratorHolder;

            template <typename T, typename SamplesBIIterator>
                class SamplesBIIteratorHolder;
        }
    }

    namespace pub
    {
        class PublisherListener;

        template <typename DELEGATE>
        class TPublisher;
    }

    namespace topic
    {
        template <typename DELEGATE>
        class TTopicDescription;

        template <typename T>
        class TopicListener;

        template <typename T, template <typename Q> class DELEGATE>
        class Topic;

        template <typename T, template <typename Q> class DELEGATE>
        class ContentFilteredTopic;

        namespace detail
        {
            template <typename T>
            class ContentFilteredTopic;
        }
    }
}


namespace org
{
namespace eclipse
{
namespace cyclonedds
{

    namespace domain {
        class DomainParticipantDelegate;
    }

    namespace sub {
        class SubscriberDelegate;
    }

    namespace pub {
        class PublisherDelegate;
    }

    namespace topic {
        template <class TOPIC>
        class TopicTraits;

        class TopicDescriptionDelegate;
    }
}
}
}

#endif /* LITE_FORWARD_DECLARATIONS_HPP_ */
