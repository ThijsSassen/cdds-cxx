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
#ifndef CYCLONEDDS_DDS_SUB_STATUS_DATASTATE_IMPL_HPP_
#define CYCLONEDDS_DDS_SUB_STATUS_DATASTATE_IMPL_HPP_

/**
 * @file
 */

#include <dds/sub/status/DataState.hpp>

/*
 * OMG PSM class declaration
 */

// Implementation

namespace dds
{
namespace sub
{
namespace status
{


inline const SampleState SampleState::read()
{
    return SampleState(0x0001 << 0u);
}

inline const SampleState SampleState::not_read()
{
    return SampleState(0x0001 << 1u);
}

inline const SampleState SampleState::any()
{
    return SampleState(0xffff);
}

inline const ViewState ViewState::new_view()
{
    return ViewState(0x0001 << 0u);
}

inline const ViewState ViewState::not_new_view()
{
    return ViewState(0x0001 << 1u);
}

inline const ViewState ViewState::any()
{
    return ViewState(0xffff);
}

inline const InstanceState InstanceState::alive()
{
    return InstanceState(0x0001 << 0u);
}

inline const InstanceState InstanceState::not_alive_disposed()
{
    return InstanceState(0x0001 << 1u);
}

inline const InstanceState InstanceState::not_alive_no_writers()
{
    return InstanceState(0x0001 << 2u);
}

inline const InstanceState InstanceState::not_alive_mask()
{
    return not_alive_disposed() | not_alive_no_writers();
}

inline const InstanceState InstanceState::any()
{
    return InstanceState(0xffff);
}


} /* namespace status */
} /* namespace sub */
} /* namespace dds */

// End of implementation

#endif /* CYCLONEDDS_DDS_SUB_STATUS_DATASTATE_IMPL_HPP_ */
