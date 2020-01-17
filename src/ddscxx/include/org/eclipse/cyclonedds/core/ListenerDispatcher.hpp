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
#ifndef CYCLONEDDS_CORE_LISTENERDISPATCHER_H_
#define CYCLONEDDS_CORE_LISTENERDISPATCHER_H_

#include "dds/dds.h"

extern "C"
{
  extern OMG_DDS_API void callback_on_inconsistent_topic
    (dds_entity_t topic, dds_inconsistent_topic_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_offered_deadline_missed
    (dds_entity_t writer, dds_offered_deadline_missed_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_offered_incompatible_qos
    (dds_entity_t writer, dds_offered_incompatible_qos_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_liveliness_lost
    (dds_entity_t writer, dds_liveliness_lost_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_publication_matched
    (dds_entity_t writer, dds_publication_matched_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_requested_deadline_missed
    (dds_entity_t reader, dds_requested_deadline_missed_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_requested_incompatible_qos
    (dds_entity_t reader, dds_requested_incompatible_qos_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_sample_rejected
    (dds_entity_t reader, dds_sample_rejected_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_liveliness_changed
    (dds_entity_t reader, dds_liveliness_changed_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_data_available (dds_entity_t reader, void* arg);

  extern OMG_DDS_API void callback_on_subscription_matched
    (dds_entity_t reader, dds_subscription_matched_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_sample_lost
    (dds_entity_t reader, dds_sample_lost_status_t status, void* arg);

  extern OMG_DDS_API void callback_on_data_readers (dds_entity_t subscriber, void* arg);
}

#endif /* CYCLONEDDS_CORE_LISTENERDISPATCHER_H_ */
