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
#ifndef CYCLONEDDS_DDS_TOPIC_TTOPICDESCRIPTION_HPP_
#define CYCLONEDDS_DDS_TOPIC_TTOPICDESCRIPTION_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/topic/TTopicDescription.hpp>

// Implementation

namespace dds
{
namespace topic
{

template <typename DELEGATE>
TTopicDescription<DELEGATE>::~TTopicDescription()
{
}

template <typename DELEGATE>
const std::string& TTopicDescription<DELEGATE>::name() const
{
    return this->delegate()->name();
}

template <typename DELEGATE>
const std::string& TTopicDescription<DELEGATE>::type_name() const
{
    return this->delegate()->type_name();
}

template <typename DELEGATE>
const dds::domain::DomainParticipant& TTopicDescription<DELEGATE>::domain_participant() const
{
    return this->delegate()->domain_participant();
}

}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_TOPIC_TTOPICDESCRIPTION_HPP_ */
