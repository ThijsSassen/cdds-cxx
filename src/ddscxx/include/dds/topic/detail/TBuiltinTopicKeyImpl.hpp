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
#ifndef CYCLONEDDS_DDS_TOPIC_DETAIL_TBUILTINTOPICKEY_IMPL_HPP_
#define CYCLONEDDS_DDS_TOPIC_DETAIL_TBUILTINTOPICKEY_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/topic/TBuiltinTopicKey.hpp>

// Implementation

namespace dds
{
namespace topic
{

template <typename D>
const int32_t* TBuiltinTopicKey<D>::value() const
{
    return this->delegate().value();
}

template <typename D>
void TBuiltinTopicKey<D>::value(int32_t v[])
{
    return this->delegate().value(v);
}

}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_TOPIC_DETAIL_TBUILTINTOPICKEY_IMPL_HPP_ */
