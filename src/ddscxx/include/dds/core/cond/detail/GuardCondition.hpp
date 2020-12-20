/*
 * Copyright(c) 2006 to 2020 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef CYCLONEDDS_DDS_CORE_COND_DETAIL_GUARDCONDITION_HPP_
#define CYCLONEDDS_DDS_CORE_COND_DETAIL_GUARDCONDITION_HPP_

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
class GuardConditionDelegate;
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
class TGuardCondition;

namespace detail
{
typedef dds::core::cond::TGuardCondition<org::eclipse::cyclonedds::core::cond::GuardConditionDelegate> GuardCondition;
}
}
}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_COND_DETAIL_GUARDCONDITION_HPP_ */
