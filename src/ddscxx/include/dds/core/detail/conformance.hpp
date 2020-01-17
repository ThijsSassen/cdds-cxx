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
#ifndef CYCLONEDDS_DDS_CORE_DETAIL_CONFORMANCE_HPP_
#define CYCLONEDDS_DDS_CORE_DETAIL_CONFORMANCE_HPP_

// Implementation

/**
 * @file
 * @internal
 * @note Values 'set' in this file should be mirrored in etc/doxygen_isocpp2_common.cfg
 * in order to ensure the doxygen documentation includes all supported QoS
 * and features and ting.
 */

#define OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT                FULL
// #define OMG_DDS_MULTI_TOPIC_SUPPORT                         FULL
#define OMG_DDS_PERSISTENCE_SUPPORT                         FULL
#define OMG_DDS_OWNERSHIP_SUPPORT                           FULL
#define OMG_DDS_OBJECT_MODEL_SUPPORT                        FULL
// #define OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT   FULL
// #define OMG_DDS_X_TYPES_BUILTIN_TOPIC_TYPES_SUPPORT         FULL

#define OMG_DDS_HAS_PRETTY_PRINT_COUT 1
// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_DETAIL_CONFORMANCE_HPP_ */
