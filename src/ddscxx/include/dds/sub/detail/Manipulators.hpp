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
#ifndef CYCLONEDDS_DDS_SUB_DETAIL_MANIPULATOR_HPP_
#define CYCLONEDDS_DDS_SUB_DETAIL_MANIPULATOR_HPP_

/**
 * @file
 */

#include <dds/sub/Query.hpp>

namespace dds
{
namespace sub
{
namespace functors
{
namespace detail
{

class MaxSamplesManipulatorFunctor
{
public:
    MaxSamplesManipulatorFunctor(uint32_t n) :
        n_(n)
    {
    }

    template<typename S>
    void operator()(S& s)
    {
        s.max_samples(n_);
    }
private:
    uint32_t n_;
};

class ContentFilterManipulatorFunctor
{
public:
    ContentFilterManipulatorFunctor(const dds::sub::Query& q) :
        query_(q)
    {
    }

    template<typename S>
    void operator()(S& s)
    {
        s.content(query_);
    }
private:
    const dds::sub::Query query_;
};

class StateFilterManipulatorFunctor
{
public:
    StateFilterManipulatorFunctor(
        const dds::sub::status::DataState& s) :
        state_(s)
    {
    }

    template<typename S>
    void operator()(S& s)
    {
        s.state(state_);
    }
private:
    dds::sub::status::DataState state_;
};

class InstanceManipulatorFunctor
{
public:
    InstanceManipulatorFunctor(const dds::core::InstanceHandle& h) :
        handle_(h)
    {
    }

    template<typename S>
    void operator()(S& s)
    {
        s.instance(handle_);
    }
private:
    dds::core::InstanceHandle handle_;
};

class NextInstanceManipulatorFunctor
{
public:
    NextInstanceManipulatorFunctor(
        const dds::core::InstanceHandle& h) :
        handle_(h)
    {
    }

    template<typename S>
    void operator()(S& s)
    {
        s.next_instance(handle_);
    }
private:
    dds::core::InstanceHandle handle_;
};


}
}
}
}



#endif /* CYCLONEDDS_DDS_SUB_DETAIL_MANIPULATOR_HPP_ */
