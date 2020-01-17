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

#ifndef CYCLONEDDS_DOMAIN_DOMAINPARTICIPANT_LISTENER_HPP_
#define CYCLONEDDS_DOMAIN_DOMAINPARTICIPANT_LISTENER_HPP_

#include <dds/domain/DomainParticipantListener.hpp>
#include <org/eclipse/cyclonedds/topic/AnyTopicListener.hpp>


namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace domain
{

class OMG_DDS_API DomainParticipantListener :
    public virtual dds::domain::DomainParticipantListener,
    public virtual org::eclipse::cyclonedds::topic::AnyTopicListener
{
public:
    virtual ~DomainParticipantListener() { }
};


class OMG_DDS_API NoOpDomainParticipantListener :
    public virtual dds::domain::NoOpDomainParticipantListener,
    public virtual org::eclipse::cyclonedds::topic::NoOpAnyTopicListener
{
public:
    virtual ~NoOpDomainParticipantListener()  { }
};

}
}
}
}

#endif /* CYCLONEDDS_DOMAIN_DOMAINPARTICIPANT_LISTENER_HPP_ */
