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
#ifndef CYCLONEDDS_DDS_SUB_SHARED_SAMPLES_IMPL_HPP_
#define CYCLONEDDS_DDS_SUB_SHARED_SAMPLES_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */

// Implementation

namespace dds
{
namespace sub
{

template <typename T, template <typename Q> class DELEGATE>
SharedSamples<T, DELEGATE>::SharedSamples() : delegate_(new DELEGATE<T>()) { }

template <typename T, template <typename Q> class DELEGATE>
SharedSamples<T, DELEGATE>::SharedSamples(dds::sub::LoanedSamples<T> ls) : delegate_(new DELEGATE<T>(ls)) { }

template <typename T, template <typename Q> class DELEGATE>
SharedSamples<T, DELEGATE>::~SharedSamples() {  }

template <typename T, template <typename Q> class DELEGATE>
SharedSamples<T, DELEGATE>::SharedSamples(const SharedSamples& other)
{
    delegate_ = other.delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
typename SharedSamples<T, DELEGATE>::const_iterator SharedSamples<T, DELEGATE>::begin() const
{
    return delegate()->begin();
}

template <typename T, template <typename Q> class DELEGATE>
typename SharedSamples<T, DELEGATE>::const_iterator SharedSamples<T, DELEGATE>::end() const
{
    return delegate()->end();
}

template <typename T, template <typename Q> class DELEGATE>
const typename SharedSamples<T, DELEGATE>::DELEGATE_REF_T& SharedSamples<T, DELEGATE>::delegate() const
{
    return delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
typename SharedSamples<T, DELEGATE>::DELEGATE_REF_T& SharedSamples<T, DELEGATE>::delegate()
{
    return delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
uint32_t SharedSamples<T, DELEGATE>::length() const
{
    return delegate_->length();
}

}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_SUB_SHARED_SAMPLES_IMPL_HPP_ */
