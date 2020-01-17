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

#ifndef CYCLONEDDS_TOPIC_TOPICTRAITS_HPP_
#define CYCLONEDDS_TOPIC_TOPICTRAITS_HPP_

#include <string.h>
#include <org/eclipse/cyclonedds/topic/DataRepresentation.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace topic
{

typedef void (*copyInFunction)(const void *, void *);
typedef void (*copyOutFunction)(const void *, void *);


template <class TOPIC> class TopicTraits
{
public:
    static ::org::eclipse::cyclonedds::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::eclipse::cyclonedds::topic::INVALID_REPRESENTATION;
    }

    static ::std::vector<uint8_t> getMetaData()
    {
        return ::std::vector<uint8_t>();
    }

    static ::std::vector<uint8_t> getTypeHash()
    {
        return ::std::vector<uint8_t>();
    }

    static ::std::vector<uint8_t> getExtentions()
    {
        return ::std::vector<uint8_t>();
    }

    static const char *getKeyList()
    {
        return "ExampleKeylist";
    }

    static const char *getTypeName()
    {
        return "ExampleName";
    }

    static const dds_topic_descriptor_t *getDescriptor()
    {
        return  NULL;
    }

    static copyInFunction getCopyIn()
    {
        return NULL;
    }

    static copyOutFunction getCopyOut()
    {
        return NULL;
    }

    static size_t getSampleSize()
    {
        return 0;
    }
};

}
}
}
}

#endif /* CYCLONEDDS_TOPIC_TOPICTRAITS_HPP_ */
