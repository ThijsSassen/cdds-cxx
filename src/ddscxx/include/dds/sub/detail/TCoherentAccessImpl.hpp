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
#ifndef CYCLONEDDS_DDS_SUB_TCOHERENTACCESS_IMPL_HPP_
#define CYCLONEDDS_DDS_SUB_TCOHERENTACCESS_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/sub/TCoherentAccess.hpp>

// Implementation

namespace dds
{
namespace sub
{

template <typename DELEGATE>
TCoherentAccess<DELEGATE>::TCoherentAccess(const dds::sub::Subscriber& sub) : dds::core::Value<DELEGATE>(sub)  {  }

template <typename DELEGATE>
void TCoherentAccess<DELEGATE>::end()
{
    this->delegate().end();
}

template <typename DELEGATE>
TCoherentAccess<DELEGATE>::~TCoherentAccess()
{
    this->delegate().end();
}

}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_SUB_TCOHERENTACCESS_IMPL_HPP_ */
