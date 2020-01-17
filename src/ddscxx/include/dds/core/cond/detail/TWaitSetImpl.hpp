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
#ifndef CYCLONEDDS_DDS_CORE_COND_TWAITSET_HPP_
#define CYCLONEDDS_DDS_CORE_COND_TWAITSET_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/cond/TWaitSet.hpp>
#include <org/eclipse/cyclonedds/core/ReportUtils.hpp>

// Implementation
namespace dds
{
namespace core
{
namespace cond
{
template <typename DELEGATE>
TWaitSet<DELEGATE>::TWaitSet()
{
    this->set_ref(new DELEGATE);
    this->delegate()->init(this->impl_);
}

template <typename DELEGATE>
TWaitSet<DELEGATE>::~TWaitSet() { }

template <typename DELEGATE>
const typename TWaitSet<DELEGATE>::ConditionSeq TWaitSet<DELEGATE>::wait(const dds::core::Duration& timeout)
{
    ConditionSeq triggered;
    return this->wait(triggered, timeout);
}

template <typename DELEGATE>
const typename TWaitSet<DELEGATE>::ConditionSeq TWaitSet<DELEGATE>::wait()
{
    ConditionSeq triggered;
    return this->wait(triggered, dds::core::Duration::infinite());
}

template <typename DELEGATE>
typename TWaitSet<DELEGATE>::ConditionSeq& TWaitSet<DELEGATE>::wait(ConditionSeq& triggered, const dds::core::Duration& timeout)
{
    return this->delegate()->wait(triggered, timeout);
}

template <typename DELEGATE>
typename TWaitSet<DELEGATE>::ConditionSeq& TWaitSet<DELEGATE>::wait(ConditionSeq& triggered)
{
    return this->wait(triggered, dds::core::Duration::infinite());
}

template <typename DELEGATE>
void TWaitSet<DELEGATE>::dispatch()
{
    this->dispatch(dds::core::Duration::infinite());
}

template <typename DELEGATE>
void TWaitSet<DELEGATE>::dispatch(const dds::core::Duration& timeout)
{
    this->delegate()->dispatch(timeout);
}

template <typename DELEGATE>
TWaitSet<DELEGATE>& TWaitSet<DELEGATE>::operator +=(const dds::core::cond::Condition& cond)
{
    this->attach_condition(cond);
    return *this;
}

template <typename DELEGATE>
TWaitSet<DELEGATE>& TWaitSet<DELEGATE>::operator -=(const dds::core::cond::Condition& cond)
{
    this->detach_condition(cond);
    return *this;
}

template <typename DELEGATE>
TWaitSet<DELEGATE>& TWaitSet<DELEGATE>::attach_condition(const dds::core::cond::Condition& cond)
{
    this->delegate()->attach_condition(cond);
    return *this;
}

template <typename DELEGATE>
bool TWaitSet<DELEGATE>::detach_condition(const dds::core::cond::Condition& cond)
{
    return this->delegate()->detach_condition(cond.delegate().get());
}

template <typename DELEGATE>
const typename TWaitSet<DELEGATE>::ConditionSeq TWaitSet<DELEGATE>::conditions() const
{
    ConditionSeq conds;
    return this->conditions(conds);
}

template <typename DELEGATE>
typename TWaitSet<DELEGATE>::ConditionSeq& TWaitSet<DELEGATE>::conditions(ConditionSeq& conds) const
{
    return this->delegate()->conditions(conds);
}

}
}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_COND_TWAITSET_HPP_ */
