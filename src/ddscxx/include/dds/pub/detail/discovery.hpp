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

#ifndef CYCLONEDDS_DDS_PUB_DETAIL_DISCOVERY_HPP_
#define CYCLONEDDS_DDS_PUB_DETAIL_DISCOVERY_HPP_

#include <dds/pub/DataWriter.hpp>

namespace dds
{
namespace pub
{

template <typename FwdIterator>
void ignore(const dds::domain::DomainParticipant& dp, FwdIterator begin, FwdIterator end)
{
    (void)dp;
    (void)begin;
    (void)end;
    ISOCPP_THROW_EXCEPTION(ISOCPP_UNSUPPORTED_ERROR, "Function not currently supported");
}

template <typename T>
::dds::core::InstanceHandleSeq
matched_subscriptions(const dds::pub::DataWriter<T>& dw)
{
    return dw.delegate()->matched_subscriptions();
}

template <typename T, typename FwdIterator>
uint32_t
matched_subscriptions(const dds::pub::DataWriter<T>& dw,
                      FwdIterator begin, uint32_t max_size)
{
    return dw.delegate()->matched_subscriptions(begin, max_size);
}

template <typename T>
const dds::topic::SubscriptionBuiltinTopicData
matched_subscription_data(const dds::pub::DataWriter<T>& dw,
                          const ::dds::core::InstanceHandle& h)
{
    return dw.delegate()->matched_subscription_data(h);
}

}
}
#endif /* CYCLONEDDS_DDS_PUB_DETAIL_DISCOVERY_HPP_ */
