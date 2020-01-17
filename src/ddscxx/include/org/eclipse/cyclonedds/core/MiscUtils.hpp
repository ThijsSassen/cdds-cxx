/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2014 PrismTech
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

#ifndef CYCLONEDDS_CORE_MISC_UTILS_HPP_
#define CYCLONEDDS_CORE_MISC_UTILS_HPP_

#include <dds/core/ddscore.hpp>
#include <org/eclipse/cyclonedds/core/Mutex.hpp>
#include "dds/dds.h"

#define STATUS_MASK_CONTAINS(mask,check) ((mask & check) == check)

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{

void
convertByteSeq(
        const dds::core::ByteSeq &from,
        void*& to,
        int32_t  size);

void
convertByteSeq(
        const void* from,
        const int32_t    size,
        dds::core::ByteSeq  &to);

void
convertStringSeq(
        const dds::core::StringSeq &from,
        char **&to);

void
convertStringSeq(
        char **from,
        uint32_t size,
        dds::core::StringSeq &to);

dds::core::Duration
convertDuration(
        const dds_duration_t &from);

dds_duration_t
convertDuration(
        const dds::core::Duration &from);

dds::core::Time
convertTime(
        const dds_time_t &from);

dds_time_t
convertTime(
        const dds::core::Time &from);

dds::core::status::StatusMask
convertStatusMask(
        const uint32_t from);

uint32_t
convertStatusMask(
        const dds::core::status::StatusMask &from);

static Mutex gpb_mutex;

}
}
}
}

#endif //CYCLONEDDS_CORE_MISC_UTILS_HPP_
