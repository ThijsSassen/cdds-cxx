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

#ifndef CYCLONEDDS_CORE_POLICY_PROPRIETARYPOLICYKIND_HPP_
#define CYCLONEDDS_CORE_POLICY_PROPRIETARYPOLICYKIND_HPP_


#include <dds/core/SafeEnumeration.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{
namespace policy
{

/*
 * Proprietary policy values
 */
struct InvalidSampleVisibility_def
{
    enum Type
    {
        NO_INVALID_SAMPLES,
        MINIMUM_INVALID_SAMPLES,
        ALL_INVALID_SAMPLES
    };
};
typedef dds::core::safe_enum<InvalidSampleVisibility_def> InvalidSampleVisibility;

struct SchedulingKind_def
{
    enum Type
    {
        SCHEDULE_DEFAULT,
        SCHEDULE_TIMESHARING,
        SCHEDULE_REALTIME
    };
};
typedef dds::core::safe_enum<SchedulingKind_def> SchedulingKind;

struct SchedulingPriorityKind_def
{
    enum Type
    {
        PRIORITY_RELATIVE,
        PRIORITY_ABSOLUTE
    };
};
typedef dds::core::safe_enum<SchedulingPriorityKind_def> SchedulingPriorityKind;

}
}
}
}
}

#endif /* CYCLONEDDS_CORE_POLICY_PROPRIETARYPOLICYKIND_HPP_ */
