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

#ifndef CYCLONEDDS_DOMAIN_PARTICIPANT_REGISTRY_HPP_
#define CYCLONEDDS_DOMAIN_PARTICIPANT_REGISTRY_HPP_

#include <org/eclipse/cyclonedds/core/EntityRegistry.hpp>
#include <org/eclipse/cyclonedds/domain/DomainParticipantDelegate.hpp>
#include <dds/domain/TDomainParticipant.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace domain
{

class OMG_DDS_API DomainParticipantRegistry {
public:

    static void insert(dds::domain::TDomainParticipant<org::eclipse::cyclonedds::domain::DomainParticipantDelegate>& participant);

    static void remove(org::eclipse::cyclonedds::domain::DomainParticipantDelegate *delegate);

private:
    static org::eclipse::cyclonedds::core::EntityRegistry
               <org::eclipse::cyclonedds::domain::DomainParticipantDelegate *,
                dds::domain::TDomainParticipant<org::eclipse::cyclonedds::domain::DomainParticipantDelegate> > registry;
};

}
}
}
}

#endif /* CYCLONEDDS_DOMAIN_PARTICIPANT_REGISTRY_HPP_ */
