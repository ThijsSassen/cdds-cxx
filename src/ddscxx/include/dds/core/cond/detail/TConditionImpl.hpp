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
#ifndef CYCLONEDDS_DDS_CORE_COND_TCONDITION_IMPL_HPP_
#define CYCLONEDDS_DDS_CORE_COND_TCONDITION_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/detail/ReferenceImpl.hpp>
#include <dds/core/cond/TCondition.hpp>
#include <org/eclipse/cyclonedds/core/ReportUtils.hpp>

// Implementation
namespace dds
{
namespace core
{
namespace cond
{

template <typename DELEGATE>
TCondition<DELEGATE>::~TCondition()
{
}

template <typename DELEGATE>
template <typename Functor>
void TCondition<DELEGATE>::handler(Functor& func)
{
    this->delegate()->set_handler(func);
}

template <typename DELEGATE>
void TCondition<DELEGATE>::reset_handler()
{
    this->delegate()->reset_handler();
}

template <typename DELEGATE>
void TCondition<DELEGATE>::dispatch()
{
    this->delegate()->dispatch();
}

template <typename DELEGATE>
bool TCondition<DELEGATE>::trigger_value() const
{
    return this->delegate()->trigger_value();
}

}
}
}
// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_COND_TCONDITION_IMPL_HPP_ */
