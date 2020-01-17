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
#ifndef CYCLONEDDS_DDS_CORE_COND_DETAIL_STATUSCONDITION_HPP_
#define CYCLONEDDS_DDS_CORE_COND_DETAIL_STATUSCONDITION_HPP_

/**
 * @file
 */

// Implementation
namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{
namespace cond
{
class StatusConditionDelegate;
}
}
}
}
}

namespace dds
{
namespace core
{
namespace cond
{

template <typename DELEGATE>
class TStatusCondition;

namespace detail
{
typedef dds::core::cond::TStatusCondition<org::eclipse::cyclonedds::core::cond::StatusConditionDelegate> StatusCondition;
}
}
}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_COND_DETAIL_STATUSCONDITION_HPP_ */
