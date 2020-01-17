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


#include <dds/pub/discovery.hpp>

namespace dds
{
namespace pub
{

void ignore(
    const dds::domain::DomainParticipant& dp,
    const dds::core::InstanceHandle& handle)
{
    DDSCXX_UNUSED_ARG(dp);
    DDSCXX_UNUSED_ARG(handle);
    ISOCPP_THROW_EXCEPTION(ISOCPP_UNSUPPORTED_ERROR, "Function not currently supported");
}

}
}
