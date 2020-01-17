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

#ifndef CYCLONEDDS_DDS_TOPIC_DETAIL_FIND_HPP_
#define CYCLONEDDS_DDS_TOPIC_DETAIL_FIND_HPP_


#include <org/eclipse/cyclonedds/topic/find.hpp>


#include <string>


namespace dds
{
namespace topic
{

template <typename TOPIC>
TOPIC
find(const dds::domain::DomainParticipant& dp, const std::string& topic_name)
{
    TOPIC t = org::eclipse::cyclonedds::topic::finder<TOPIC, typename TOPIC::DELEGATE_T>::find(dp, topic_name);

    return t;
}


}
}

#endif /* CYCLONEDDS_DDS_TOPIC_DETAIL_FIND_HPP_ */
