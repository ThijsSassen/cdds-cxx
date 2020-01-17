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
#ifndef CYCLONEDDS_DDS_CORE_POLICY_TQOSPOLICYCOUNT_IMPL_HPP_
#define CYCLONEDDS_DDS_CORE_POLICY_TQOSPOLICYCOUNT_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/policy/TQosPolicyCount.hpp>

// Implementation

namespace dds
{
namespace core
{
namespace policy
{

template <typename D>
TQosPolicyCount<D>::TQosPolicyCount(QosPolicyId policy_id, int32_t count) : dds::core::Value<D>(policy_id, count) { }

template <typename D>
TQosPolicyCount<D>::TQosPolicyCount(const TQosPolicyCount& other) : dds::core::Value<D>(other.policy_id(), other.count()) { }

template <typename D> QosPolicyId TQosPolicyCount<D>::policy_id() const
{
    return this->delegate().policy_id();
}

template <typename D>
int32_t TQosPolicyCount<D>::count() const
{
    return this->delegate().count();
}

}
}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_POLICY_TQOSPOLICYCOUNT_IMPL_HPP_ */
