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

#ifndef CYCLONEDDS_TOPIC_ANYTOPICDELEGATE_HPP_
#define CYCLONEDDS_TOPIC_ANYTOPICDELEGATE_HPP_


#include <dds/core/types.hpp>
#include <org/eclipse/cyclonedds/topic/TopicTraits.hpp>
#include <org/eclipse/cyclonedds/core/EntityDelegate.hpp>
#include <org/eclipse/cyclonedds/topic/TopicDescriptionDelegate.hpp>


namespace dds { namespace topic {
template <typename DELEGATE>
class TAnyTopic;
} }


namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace topic
{

class OMG_DDS_API AnyTopicDelegate :
    public virtual org::eclipse::cyclonedds::core::EntityDelegate,
    public virtual org::eclipse::cyclonedds::topic::TopicDescriptionDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< AnyTopicDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< AnyTopicDelegate >::weak_ref_type weak_ref_type;

    AnyTopicDelegate(const dds::topic::qos::TopicQos& qos,
                     const dds::domain::DomainParticipant& dp,
                     const std::string& name,
                     const std::string& type_name,
                     dds_entity_t ddsc_topic);

    virtual ~AnyTopicDelegate();

public:
    /* DDS API mirror. */
    dds::topic::qos::TopicQos qos() const;
    void qos(const dds::topic::qos::TopicQos& qos);

    ::dds::core::status::InconsistentTopicStatus inconsistent_topic_status() const;

    std::string reader_expression() const;

    TEMP_TYPE reader_parameters() const;
    //@todo c_value *reader_parameters() const;

public:
    dds::topic::TAnyTopic<AnyTopicDelegate> wrapper_to_any();

    void init(ObjectDelegate::weak_ref_type weak_ref);

    void listener_notify(ObjectDelegate::ref_type,
                         uint32_t,
                         void *,
                         void *) {}

    static dds::topic::TAnyTopic<AnyTopicDelegate>
    discover_topic(const dds::domain::DomainParticipant& dp,
                   const std::string& name,
                   const dds::core::Duration& timeout);

    static void
    discover_topics(const dds::domain::DomainParticipant& dp,
                    std::vector<dds::topic::TAnyTopic<AnyTopicDelegate> >& topics,
                    uint32_t max_size);

    void set_copy_out(org::eclipse::cyclonedds::topic::copyOutFunction copyOut);
    org::eclipse::cyclonedds::topic::copyOutFunction get_copy_out();

    void set_sample(void* sample);
    void* get_sample();

protected:
    AnyTopicDelegate(const dds::topic::qos::TopicQos& qos,
                     const dds::domain::DomainParticipant& dp,
                     const std::string& name,
                     const std::string& type_name);

    dds::topic::qos::TopicQos qos_;
    org::eclipse::cyclonedds::topic::copyOutFunction copyOut;
    void* sample_;
};

}
}
}
}

#endif /* CYCLONEDDS_TOPIC_ANYTOPICDELEGATE_HPP_ */
