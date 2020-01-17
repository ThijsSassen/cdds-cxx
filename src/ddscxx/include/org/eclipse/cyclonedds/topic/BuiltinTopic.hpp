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


#ifndef CYCLONEDDS_TOPIC_BUILTIN_TOPIC_HPP_
#define CYCLONEDDS_TOPIC_BUILTIN_TOPIC_HPP_


#include <org/eclipse/cyclonedds/topic/TBuiltinTopic.hpp>


namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace topic
{

typedef TCMParticipantBuiltinTopicData<CMParticipantBuiltinTopicDataDelegate>
CMParticipantBuiltinTopicData;

typedef TCMPublisherBuiltinTopicData<CMPublisherBuiltinTopicDataDelegate>
CMPublisherBuiltinTopicData;

typedef TCMSubscriberBuiltinTopicData<CMSubscriberBuiltinTopicDataDelegate>
CMSubscriberBuiltinTopicData;

typedef TCMDataWriterBuiltinTopicData<CMDataWriterBuiltinTopicDataDelegate>
CMDataWriterBuiltinTopicData;

typedef TCMDataReaderBuiltinTopicData<CMDataReaderBuiltinTopicDataDelegate>
CMDataReaderBuiltinTopicData;

}
}
}
}

#endif /* CYCLONEDDS_TOPIC_BUILTIN_TOPIC_HPP_ */
