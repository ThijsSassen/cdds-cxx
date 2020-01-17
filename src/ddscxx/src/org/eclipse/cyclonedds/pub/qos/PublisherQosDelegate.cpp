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
#include <org/eclipse/cyclonedds/pub/qos/PublisherQosDelegate.hpp>

#include <cassert>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace pub
{
namespace qos
{

PublisherQosDelegate::PublisherQosDelegate()
{
}

PublisherQosDelegate::PublisherQosDelegate(
    const PublisherQosDelegate& other)
    : presentation_(other.presentation_),
      partition_(other.partition_),
      gdata_(other.gdata_),
      factory_policy_(other.factory_policy_)
{
}

PublisherQosDelegate::~PublisherQosDelegate()
{
}

void
PublisherQosDelegate::policy(const dds::core::policy::Presentation& presentation)
{
    presentation.delegate().check();
    presentation_ = presentation;
}

void
PublisherQosDelegate::policy(const dds::core::policy::Partition& partition)
{
    partition.delegate().check();
    partition_ = partition;
}

void
PublisherQosDelegate::policy(const dds::core::policy::GroupData& gdata)
{
    gdata.delegate().check();
    gdata_ = gdata;
}

void
PublisherQosDelegate::policy(const dds::core::policy::EntityFactory& factory_policy)
{
    factory_policy.delegate().check();
    factory_policy_ = factory_policy;
}

dds_qos_t*
PublisherQosDelegate::ddsc_qos() const
{
    dds_qos_t* qos = dds_create_qos();
    presentation_   .delegate().set_c_policy(qos);
    partition_      .delegate().set_c_policy(qos);
    gdata_          .delegate().set_c_policy(qos);
    factory_policy_ .delegate().set_c_policy(qos);
    return qos;
}

void
PublisherQosDelegate::ddsc_qos(const dds_qos_t* qos)
{
    assert(qos);
    presentation_   .delegate().set_iso_policy(qos);
    partition_      .delegate().set_iso_policy(qos);
    gdata_          .delegate().set_iso_policy(qos);
    factory_policy_ .delegate().set_iso_policy(qos);
}

void
PublisherQosDelegate::named_qos(const struct _DDS_NamedPublisherQos &qos)
{
    (void)qos;
#if 0
    /* We only need the QoS part of the named QoS. */
    const struct _DDS_PublisherQos *q = &qos.publisher_qos;
    /* The idl policies are aligned the same as the ddsc/builtin representation.
     * So, cast and use the ddsc policy translations (or builtin when available). */
    presentation_   .delegate().v_policy((v_presentationPolicy&)    (q->presentation)  );
    partition_      .delegate().v_policy((v_builtinPartitionPolicy&)(q->partition)     );
    gdata_          .delegate().v_policy((v_builtinGroupDataPolicy&)(q->group_data)    );
    factory_policy_ .delegate().v_policy((v_entityFactoryPolicy&)   (q->entity_factory));
#endif
}

void
PublisherQosDelegate::check() const
{
    /* Policies are checked when set.
     * No consistency check between policies needed. */
}

bool
PublisherQosDelegate::operator ==(const PublisherQosDelegate& other) const
{
    return other.presentation_   == presentation_ &&
           other.partition_      == partition_    &&
           other.gdata_          == gdata_        &&
           other.factory_policy_ == factory_policy_;
}

PublisherQosDelegate&
PublisherQosDelegate::operator =(const PublisherQosDelegate& other)
{
    presentation_   = other.presentation_;
    partition_      = other.partition_;
    gdata_          = other.gdata_;
    factory_policy_ = other.factory_policy_;
    return *this;
}

}
}
}
}
}
