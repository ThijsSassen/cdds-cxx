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

#ifndef CYCLONEDDS_CORE_ENTITY_DELEGATE_HPP_
#define CYCLONEDDS_CORE_ENTITY_DELEGATE_HPP_

#include <dds/core/status/State.hpp>
#include <dds/core/InstanceHandle.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <org/eclipse/cyclonedds/core/DDScObjectDelegate.hpp>
#include <org/eclipse/cyclonedds/ForwardDeclarations.hpp>
#include <org/eclipse/cyclonedds/core/status/StatusDelegate.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{

class OMG_DDS_API EntityDelegate :
    public virtual ::org::eclipse::cyclonedds::core::DDScObjectDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< EntityDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< EntityDelegate >::weak_ref_type weak_ref_type;

    EntityDelegate();
    virtual ~EntityDelegate();

    /**
     *  @internal Enables this entity.
     */
    void enable();

    ::dds::core::status::StatusMask status_changes() const;

    ::dds::core::InstanceHandle instance_handle() const;

    bool contains_entity(const ::dds::core::InstanceHandle& handle);

    ObjectDelegate::ref_type get_statusCondition();

    virtual void close();

    virtual void retain();

    void *listener_get() const;

protected:
    void listener_set(void *listener,
            const dds::core::status::StatusMask& mask);

public:
    const dds::core::status::StatusMask get_listener_mask() const ;

    bool obtain_callback_lock() ;
    void release_callback_lock() ;

    // Topic callback
    virtual void on_inconsistent_topic(dds_entity_t topic,
          org::eclipse::cyclonedds::core::InconsistentTopicStatusDelegate &) ;


    // Writer callbacks
    virtual void on_offered_deadline_missed(dds_entity_t writer,
          org::eclipse::cyclonedds::core::OfferedDeadlineMissedStatusDelegate &) ;

    virtual void on_offered_incompatible_qos(dds_entity_t writer,
          org::eclipse::cyclonedds::core::OfferedIncompatibleQosStatusDelegate &) ;

    virtual void on_liveliness_lost(dds_entity_t writer,
          org::eclipse::cyclonedds::core::LivelinessLostStatusDelegate &) ;

    virtual void on_publication_matched(dds_entity_t writer,
          org::eclipse::cyclonedds::core::PublicationMatchedStatusDelegate &) ;


    // Reader callbacks
    virtual void on_requested_deadline_missed(dds_entity_t reader,
          org::eclipse::cyclonedds::core::RequestedDeadlineMissedStatusDelegate &);

    virtual void on_requested_incompatible_qos(dds_entity_t reader,
          org::eclipse::cyclonedds::core::RequestedIncompatibleQosStatusDelegate &);

    virtual void on_sample_rejected(dds_entity_t reader,
          org::eclipse::cyclonedds::core::SampleRejectedStatusDelegate &);

    virtual void on_liveliness_changed(dds_entity_t reader,
          org::eclipse::cyclonedds::core::LivelinessChangedStatusDelegate &);

    virtual void on_data_available(dds_entity_t reader);

    virtual void on_subscription_matched(dds_entity_t reader,
          org::eclipse::cyclonedds::core::SubscriptionMatchedStatusDelegate &);

    virtual void on_sample_lost(dds_entity_t reader,
          org::eclipse::cyclonedds::core::SampleLostStatusDelegate &);


    // Subscriber callback
    virtual void on_data_readers(dds_entity_t subscriber);

protected:
    static volatile unsigned int entityID_;
    bool enabled_;
    dds::core::status::StatusMask listener_mask;
    void prevent_callbacks();
    long callback_count;
    dds_listener_t *listener_callbacks;

private:
    void *listener;
    ObjectDelegate::weak_ref_type myStatusCondition;
    void *callback_mutex;
    void *callback_cond;
};

}
}
}
}

#endif /* CYCLONEDDS_CORE_ENTITY_DELEGATE_HPP_ */
