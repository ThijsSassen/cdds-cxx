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
#ifndef CYCLONEDDS_DDS_PUB_TSUSPENDEDPUBLICATION_IMPL_HPP_
#define CYCLONEDDS_DDS_PUB_TSUSPENDEDPUBLICATION_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/pub/TSuspendedPublication.hpp>
#include <org/eclipse/cyclonedds/core/ReportUtils.hpp>

// Implementation

namespace dds
{
namespace pub
{

template <typename DELEGATE>
TSuspendedPublication<DELEGATE>::TSuspendedPublication(const dds::pub::Publisher& pub) : dds::core::Value<DELEGATE>(pub) { }

template <typename DELEGATE>
void TSuspendedPublication<DELEGATE>::resume()
{
    this->delegate().resume();
}

template <typename DELEGATE>
TSuspendedPublication<DELEGATE>::~TSuspendedPublication()
{
    this->delegate().resume();
}

}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_PUB_TSUSPENDEDPUBLICATION_IMPL_HPP_ */
