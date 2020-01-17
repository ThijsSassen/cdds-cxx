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
#ifndef CYCLONEDDS_DDS_CORE_COND_DETAIL_WAITSET_HPP_
#define CYCLONEDDS_DDS_CORE_COND_DETAIL_WAITSET_HPP_

/**
 * @file
 */

// Implementation

#include <dds/core/cond/detail/TWaitSetImpl.hpp>
#include <org/eclipse/cyclonedds/core/cond/WaitSetDelegate.hpp>

namespace dds
{
namespace core
{
namespace cond
{
namespace detail
{
typedef dds::core::cond::TWaitSet<org::eclipse::cyclonedds::core::cond::WaitSetDelegate> WaitSet;
}
}
}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_COND_DETAIL_WAITSET_HPP_ */
