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

#include <org/eclipse/cyclonedds/domain/DomainParticipantRegistry.hpp>


org::eclipse::cyclonedds::core::EntityRegistry
  <org::eclipse::cyclonedds::domain::DomainParticipantDelegate *,
   dds::domain::TDomainParticipant<org::eclipse::cyclonedds::domain::DomainParticipantDelegate> > org::eclipse::cyclonedds::domain::DomainParticipantRegistry::registry;


void
org::eclipse::cyclonedds::domain::DomainParticipantRegistry::insert(
    dds::domain::TDomainParticipant<org::eclipse::cyclonedds::domain::DomainParticipantDelegate>& participant)
{
    registry.insert(participant.delegate().get(), participant);
}

void
org::eclipse::cyclonedds::domain::DomainParticipantRegistry::remove(
    org::eclipse::cyclonedds::domain::DomainParticipantDelegate *delegate)
{
    registry.remove(delegate);
}
