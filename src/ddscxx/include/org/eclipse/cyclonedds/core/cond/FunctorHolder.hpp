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

#ifndef CYCLONEDDS_CORE_COND_FUNCTOR_HOLDER_HPP_
#define CYCLONEDDS_CORE_COND_FUNCTOR_HOLDER_HPP_

namespace dds
{
namespace core
{
namespace cond
{
template <typename DELEGATE> class TCondition;
}
}
}

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{
namespace cond
{

class ConditionDelegate;

class FunctorHolderBase
{
public:
    FunctorHolderBase() { };

    virtual ~FunctorHolderBase() { };

    virtual void dispatch(dds::core::cond::TCondition<org::eclipse::cyclonedds::core::cond::ConditionDelegate> &condition) = 0;
};

template <typename FUN>
class FunctorHolder : public FunctorHolderBase
{
public:
    /* Remove const to be able to call non-const functors. */
    FunctorHolder(FUN &functor) : myFunctor(functor)
    {
    }

    virtual ~FunctorHolder() { };

    void dispatch(dds::core::cond::TCondition<org::eclipse::cyclonedds::core::cond::ConditionDelegate> &condition)
    {
        myFunctor(condition);
    }

private:
    FUN &myFunctor;
};

}
}
}
}
}

#endif  /* CYCLONEDDS_CORE_COND_FUNCTOR_HOLDER_HPP_ */
