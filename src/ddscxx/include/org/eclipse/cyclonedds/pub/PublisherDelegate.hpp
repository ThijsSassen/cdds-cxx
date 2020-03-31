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


/**
 * @file
 */

#ifndef OMG_IDDS_PUB_PUBLISHER_DELEGATE_HPP_
#define OMG_IDDS_PUB_PUBLISHER_DELEGATE_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dds/core/types.hpp>
#include <dds/core/Duration.hpp>
#include <dds/core/status/State.hpp>
#include <dds/pub/qos/PublisherQos.hpp>
#include <dds/pub/qos/DataWriterQos.hpp>
#include <dds/domain/DomainParticipant.hpp>

#include <org/eclipse/cyclonedds/ForwardDeclarations.hpp>
#include <org/eclipse/cyclonedds/core/EntityDelegate.hpp>
#include <org/eclipse/cyclonedds/core/EntitySet.hpp>
#include <org/eclipse/cyclonedds/pub/AnyDataWriterDelegate.hpp>


namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace pub
{

class OMG_DDS_API PublisherDelegate : public org::eclipse::cyclonedds::core::EntityDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< PublisherDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< PublisherDelegate >::weak_ref_type weak_ref_type;

    PublisherDelegate(const dds::domain::DomainParticipant& dp,
                      const dds::pub::qos::PublisherQos& qos,
                      dds::pub::PublisherListener* listener,
                      const dds::core::status::StatusMask& event_mask);

    virtual ~PublisherDelegate();

    void init(ObjectDelegate::weak_ref_type weak_ref);

    void close();

    const dds::pub::qos::PublisherQos& qos() const;
    void qos(const dds::pub::qos::PublisherQos& pqos);

    void default_datawriter_qos(const dds::pub::qos::DataWriterQos& dwqos);
    dds::pub::qos::DataWriterQos default_datawriter_qos() const;

    void suspend_publications();
    void resume_publications();

    void begin_coherent_changes();
    void end_coherent_changes();

    void wait_for_acknowledgments(const dds::core::Duration& max_wait);

    void listener(dds::pub::PublisherListener* listener,
                  const ::dds::core::status::StatusMask& mask);
    dds::pub::PublisherListener* listener() const;

    const dds::domain::DomainParticipant& participant() const;

    bool contains_entity(const ::dds::core::InstanceHandle& handle);

    void add_datawriter(org::eclipse::cyclonedds::core::EntityDelegate& datawriter);
    void remove_datawriter(org::eclipse::cyclonedds::core::EntityDelegate& datawriter);
    org::eclipse::cyclonedds::pub::AnyDataWriterDelegate::ref_type find_datawriter(const std::string& topic_name);

    dds::pub::TPublisher<PublisherDelegate>
    wrapper();

    bool is_auto_enable() const;

    void on_offered_deadline_missed(dds_entity_t writer,
          org::eclipse::cyclonedds::core::OfferedDeadlineMissedStatusDelegate &sd);

    void on_offered_incompatible_qos(dds_entity_t writer,
          org::eclipse::cyclonedds::core::OfferedIncompatibleQosStatusDelegate &sd);

    void on_liveliness_lost(dds_entity_t writer,
          org::eclipse::cyclonedds::core::LivelinessLostStatusDelegate &sd);

    void on_publication_matched(dds_entity_t writer,
          org::eclipse::cyclonedds::core::PublicationMatchedStatusDelegate &sd);

private:
    dds::domain::DomainParticipant dp_;
    dds::pub::qos::PublisherQos qos_;
    dds::pub::qos::DataWriterQos default_dwqos_;

    org::eclipse::cyclonedds::core::EntitySet writers;
};

}
}
}
}

#endif /* OMG_IDDS_PUB_PUBLISHER_DELEGATE_HPP_ */
