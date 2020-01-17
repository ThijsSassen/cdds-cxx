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

#ifndef CYCLONEDDS_TOPIC_TOPIC_LISTENER_HPP_
#define CYCLONEDDS_TOPIC_TOPIC_LISTENER_HPP_


#include "dds/topic/TopicListener.hpp"

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace topic
{

template <typename T>
class TopicListener : public dds::topic::TopicListener<T>
{
public:
    virtual ~TopicListener() { }
};

template <typename T>
class NoOpTopicListener : public virtual TopicListener<T>
{
public:
    virtual ~NoOpTopicListener() { }

public:
    virtual void on_inconsistent_topic(
        dds::topic::Topic<T>&,
        const dds::core::status::InconsistentTopicStatus&) { }
};

}
}
}
}

#endif /* CYCLONEDDS_TOPIC_TOPIC_LISTENER_HPP_ */
