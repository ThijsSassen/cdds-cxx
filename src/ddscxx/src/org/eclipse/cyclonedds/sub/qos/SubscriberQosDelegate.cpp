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

#include <org/eclipse/cyclonedds/core/ReportUtils.hpp>
#include <org/eclipse/cyclonedds/sub/qos/SubscriberQosDelegate.hpp>

#include <cassert>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace sub
{
namespace qos
{

SubscriberQosDelegate::SubscriberQosDelegate()
{
}

SubscriberQosDelegate::SubscriberQosDelegate(
    const SubscriberQosDelegate& other)
    : presentation_(other.presentation_),
      partition_(other.partition_),
      group_data_(other.group_data_),
      entity_factory_(other.entity_factory_)
{
}

SubscriberQosDelegate::~SubscriberQosDelegate()
{
}

void
SubscriberQosDelegate::policy(const dds::core::policy::Presentation& presentation)
{
    presentation.delegate().check();
    presentation_ = presentation;
}

void
SubscriberQosDelegate::policy(const dds::core::policy::Partition& partition)
{
    partition.delegate().check();
    partition_ = partition;
}

void
SubscriberQosDelegate::policy(const dds::core::policy::GroupData& group_data)
{
    group_data.delegate().check();
    group_data_ = group_data;
}

void
SubscriberQosDelegate::policy(const dds::core::policy::EntityFactory& entity_factory)
{
    entity_factory.delegate().check();
    entity_factory_ = entity_factory;
}

dds_qos_t*
SubscriberQosDelegate::ddsc_qos() const
{
    dds_qos_t* qos = dds_create_qos();
    presentation_   .delegate().set_c_policy(qos);
    partition_      .delegate().set_c_policy(qos);
    group_data_     .delegate().set_c_policy(qos);
    entity_factory_ .delegate().set_c_policy(qos);
    return qos;
}

void
SubscriberQosDelegate::ddsc_qos(const dds_qos_t* qos)
{
    assert(qos);
    presentation_   .delegate().set_iso_policy(qos);
    partition_      .delegate().set_iso_policy(qos);
    group_data_     .delegate().set_iso_policy(qos);
    entity_factory_ .delegate().set_iso_policy(qos);
}

void
SubscriberQosDelegate::named_qos(const struct _DDS_NamedSubscriberQos &qos)
{
    (void)qos;
#if 0
    /* We only need the QoS part of the named QoS. */
    const struct _DDS_SubscriberQos *q = &qos.subscriber_qos;
    /* The idl policies are aligned the same as the ddsc/builtin representation.
     * So, cast and use the ddsc policy translations (or builtin when available). */
    presentation_   .delegate().v_policy((v_presentationPolicy&)    (q->presentation)  );
    partition_      .delegate().v_policy((v_builtinPartitionPolicy&)(q->partition)     );
    group_data_     .delegate().v_policy((v_builtinGroupDataPolicy&)(q->group_data)    );
    entity_factory_ .delegate().v_policy((v_entityFactoryPolicy&)   (q->entity_factory));
#endif
}

void
SubscriberQosDelegate::check() const
{
    /* Policies are checked when set.
     * No consistency check between policies needed. */
}

bool
SubscriberQosDelegate::operator ==(const SubscriberQosDelegate& other) const
{
    return other.presentation_   == presentation_   &&
           other.partition_      == partition_      &&
           other.group_data_     == group_data_     &&
           other.entity_factory_ == entity_factory_;
}

SubscriberQosDelegate&
SubscriberQosDelegate::operator =(const SubscriberQosDelegate& other)
{
    presentation_   = other.presentation_;
    partition_      = other.partition_;
    group_data_     = other.group_data_;
    entity_factory_ = other.entity_factory_;
    return *this;
}

}
}
}
}
}
