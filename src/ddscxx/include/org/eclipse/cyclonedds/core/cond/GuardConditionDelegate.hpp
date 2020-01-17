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

#ifndef CYCLONEDDS_CORE_GUARD_CONDITION_DELEGATE_HPP_
#define CYCLONEDDS_CORE_GUARD_CONDITION_DELEGATE_HPP_

#include <org/eclipse/cyclonedds/core/cond/ConditionDelegate.hpp>

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

class OMG_DDS_API GuardConditionDelegate :
                         public org::eclipse::cyclonedds::core::cond::ConditionDelegate
{
public:
    GuardConditionDelegate();

    template<typename FUN>
    GuardConditionDelegate(const FUN& functor) :
       org::eclipse::cyclonedds::core::cond::ConditionDelegate(functor)
    {
    }

    ~GuardConditionDelegate();

    void close();

    virtual bool trigger_value() const;

    void trigger_value(bool value);
};

}
}
}
}
}

#endif  /* CYCLONEDDS_CORE_GUARD_CONDITION_DELEGATE_HPP_ */
