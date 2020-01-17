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

#include <org/eclipse/cyclonedds/topic/TopicDescriptionDelegate.hpp>
#include <org/eclipse/cyclonedds/core/ScopedLock.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace topic
{

TopicDescriptionDelegate::TopicDescriptionDelegate(
        const dds::domain::DomainParticipant& dp,
        const std::string& name,
        const std::string& type_name)
    : myParticipant(dp),
      myTopicName(name),
      myTypeName(type_name),
      nrDependents(0)
{
}

TopicDescriptionDelegate::~TopicDescriptionDelegate()
{
}

const std::string&
TopicDescriptionDelegate::name() const
{
    org::eclipse::cyclonedds::core::ScopedObjectLock scopedLock(*this);
    this->check();
    return myTopicName;
}

const std::string&
TopicDescriptionDelegate::type_name() const
{
    org::eclipse::cyclonedds::core::ScopedObjectLock scopedLock(*this);
    this->check();
    return myTypeName;
}

const dds::domain::DomainParticipant&
TopicDescriptionDelegate::domain_participant() const
{
    org::eclipse::cyclonedds::core::ScopedObjectLock scopedLock(*this);
    this->check();
    return myParticipant;
}

void
TopicDescriptionDelegate::incrNrDependents()
{
    nrDependents++;
}

void
TopicDescriptionDelegate::decrNrDependents()
{
    nrDependents--;
}

bool
TopicDescriptionDelegate::hasDependents() const
{
    return (nrDependents > 0);
}


}
}
}
}

