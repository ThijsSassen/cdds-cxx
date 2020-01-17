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

#include <org/eclipse/cyclonedds/core/cond/ShadowParticipant.hpp>
#include "org/eclipse/cyclonedds/core/Mutex.hpp"

org::eclipse::cyclonedds::core::cond::ShadowParticipant* 
org::eclipse::cyclonedds::core::cond::ShadowParticipant::instance_ = nullptr;

org::eclipse::cyclonedds::core::Mutex
org::eclipse::cyclonedds::core::cond::ShadowParticipant::mutex_;
