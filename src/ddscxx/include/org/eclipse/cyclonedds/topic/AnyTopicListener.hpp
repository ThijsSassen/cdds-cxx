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


#ifndef CYCLONEDDS_TOPIC_ANY_TOPIC_LISTENER_HPP_
#define CYCLONEDDS_TOPIC_ANY_TOPIC_LISTENER_HPP_


#include <dds/topic/AnyTopicListener.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace topic
{

class OMG_DDS_API AnyTopicListener
{
public:
    virtual ~AnyTopicListener() { }
};


class OMG_DDS_API NoOpAnyTopicListener : public virtual AnyTopicListener
{
public:
    virtual ~NoOpAnyTopicListener() { }
};

}
}
}
}

#endif /* CYCLONEDDS_TOPIC_ANY_TOPIC_LISTENER_HPP_ */
