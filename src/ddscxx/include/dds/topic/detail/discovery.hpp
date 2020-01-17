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

#ifndef CYCLONEDDS_DDS_TOPIC_DETAIL_DISCOVER_HPP_
#define CYCLONEDDS_DDS_TOPIC_DETAIL_DISCOVER_HPP_

#include <dds/topic/AnyTopic.hpp>
#include <dds/topic/Topic.hpp>
#include <org/eclipse/cyclonedds/topic/discovery.hpp>

#include <string>


namespace dds
{
namespace topic
{

template <typename TOPIC>
TOPIC
discover(
    const dds::domain::DomainParticipant& dp,
    const std::string& topic_name,
    const dds::core::Duration& timeout)
{
    TOPIC t = org::eclipse::cyclonedds::topic::lookup_topic<TOPIC, typename TOPIC::DELEGATE_T>::discover(dp, topic_name, timeout);

    return t;
}


template <typename ANYTOPIC, typename FwdIterator>
uint32_t
discover(
    const dds::domain::DomainParticipant& dp,
    FwdIterator begin,
    uint32_t max_size)
{
    std::vector<ANYTOPIC> list;

    org::eclipse::cyclonedds::topic::lookup_topic<ANYTOPIC, typename ANYTOPIC::DELEGATE_T>::discover(dp, list, max_size);

    FwdIterator fit = begin;
    for (typename std::vector<ANYTOPIC>::const_iterator it = list.begin(); it != list.end(); ++it) {
       *fit++ = *it;
    }

    return (uint32_t)list.size();
}

template <typename ANYTOPIC, typename BinIterator>
uint32_t
discover_all(
    const dds::domain::DomainParticipant& dp,
    BinIterator begin)
{
    std::vector<ANYTOPIC> list;

    org::eclipse::cyclonedds::topic::lookup_topic<ANYTOPIC, typename ANYTOPIC::DELEGATE_T>::discover(dp, list, (uint32_t)dds::core::LENGTH_UNLIMITED);

    BinIterator bit = begin;
    for (typename std::vector<ANYTOPIC>::const_iterator it = list.begin(); it != list.end(); ++it) {
       *bit++ = *it;
    }

    return list.size();
}


template <typename FwdIterator>
void
ignore(
    const dds::domain::DomainParticipant& dp,
    FwdIterator begin, FwdIterator end)
{
    (void)dp;
    (void)begin;
    (void)end;
    ISOCPP_THROW_EXCEPTION(ISOCPP_UNSUPPORTED_ERROR, "Function not currently supported");
}

}
}


#endif /* CYCLONEDDS_DDS_TOPIC_DETAIL_DISCOVER_HPP_ */
