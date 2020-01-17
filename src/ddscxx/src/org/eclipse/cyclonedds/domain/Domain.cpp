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

#include "org/eclipse/cyclonedds/domain/Domain.hpp"

#include "dds/dds.h"

uint32_t org::eclipse::cyclonedds::domain::any_id()
{
    /* The any_id is basically the same as cyclonedds default domain. */
    return (uint32_t)DDS_DOMAIN_DEFAULT;
}

uint32_t org::eclipse::cyclonedds::domain::default_id()
{
    return (uint32_t)DDS_DOMAIN_DEFAULT;
}
