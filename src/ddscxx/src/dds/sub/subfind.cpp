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


#include <dds/sub/find.hpp>

namespace dds
{
namespace sub
{

const Subscriber
builtin_subscriber(const dds::domain::DomainParticipant& dp)
{
    (void)dp;
    ISOCPP_THROW_EXCEPTION(ISOCPP_UNSUPPORTED_ERROR, "Function not currently supported");
#if 0
    org::eclipse::cyclonedds::sub::SubscriberDelegate::ref_type ref =
            org::eclipse::cyclonedds::sub::BuiltinSubscriberDelegate::get_builtin_subscriber(dp);
    return Subscriber(ref);
#else
    return Subscriber(dds::core::null);
#endif
}

}
}
