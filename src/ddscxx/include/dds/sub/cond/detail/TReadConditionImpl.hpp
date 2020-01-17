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
#ifndef CYCLONEDDS_DDS_CORE_COND_TREADCONDITION_IMPL_HPP_
#define CYCLONEDDS_DDS_CORE_COND_TREADCONDITION_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/sub/cond/TReadCondition.hpp>
#include <org/eclipse/cyclonedds/sub/cond/ReadConditionDelegate.hpp>

// Implementation

namespace dds
{
namespace sub
{
namespace cond
{

template <typename DELEGATE>
TReadCondition<DELEGATE>::TReadCondition(
    const dds::sub::AnyDataReader& dr,
    const dds::sub::status::DataState& status)
{
    this->set_ref(new DELEGATE(dr, status));
	this->delegate()->init(this->impl_);
}

template <typename DELEGATE>
template <typename FUN>
TReadCondition<DELEGATE>::TReadCondition(
        const dds::sub::AnyDataReader& dr,
        const dds::sub::status::DataState& status,
        FUN& functor)
{
    this->set_ref(new DELEGATE(dr, status));
	this->delegate()->init(this->impl_);
    this->delegate()->set_handler(functor);
}

template <typename DELEGATE>
TReadCondition<DELEGATE>::~TReadCondition() { }

template <typename DELEGATE>
const dds::sub::status::DataState TReadCondition<DELEGATE>::state_filter() const
{
    return this->delegate()->state_filter();
}

template <typename DELEGATE>
const AnyDataReader& TReadCondition<DELEGATE>::data_reader() const
{
    return this->delegate()->data_reader();
}

}
}
namespace core
{
namespace cond
{
template <typename DELEGATE>
TCondition<DELEGATE>::TCondition(const dds::sub::cond::TReadCondition<org::eclipse::cyclonedds::sub::cond::ReadConditionDelegate>& h)
{
    if (h.is_nil()) {
        /* We got a null object and are not really able to do a typecheck here. */
        /* So, just set a null object. */
        *this = dds::core::null;
    } else {
        this->::dds::core::Reference<DELEGATE>::impl_ = OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<DELEGATE_T>(h.delegate());
        if (h.delegate() != this->::dds::core::Reference<DELEGATE>::impl_) {
            throw dds::core::IllegalOperationError(std::string("Attempted invalid cast: ") + typeid(h).name() + " to " + typeid(*this).name());
        }
    }
}

template <typename DELEGATE>
TCondition<DELEGATE>&
TCondition<DELEGATE>::operator=(const dds::sub::cond::TReadCondition<org::eclipse::cyclonedds::sub::cond::ReadConditionDelegate>& rhs)
{
    if (this != (TCondition*)&rhs) {
        if (rhs.is_nil()) {
            /* We got a null object and are not really able to do a typecheck here. */
            /* So, just set a null object. */
            *this = dds::core::null;
        } else {
            TCondition other(rhs);
            /* Dont have to copy when the delegate is the same. */
            if (other.delegate() != this->::dds::core::Reference<DELEGATE>::impl_) {
                *this = other;
            }
        }
    }
    return *this;
}
}
}
}
// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_COND_TREADCONDITION_IMPL_HPP_ */
