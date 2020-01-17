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

#include <org/eclipse/cyclonedds/core/cond/GuardConditionDelegate.hpp>
#include <org/eclipse/cyclonedds/core/cond/WaitSetDelegate.hpp>


org::eclipse::cyclonedds::core::cond::GuardConditionDelegate::GuardConditionDelegate() :
        org::eclipse::cyclonedds::core::cond::ConditionDelegate()
{
    dds_entity_t ddsc_guard_cond;
    
    ddsc_guard_cond = dds_create_guardcondition(DDS_CYCLONEDDS_HANDLE);
    ISOCPP_DDSC_RESULT_CHECK_AND_THROW(ddsc_guard_cond, "Could not create guard condition.");
    this->set_ddsc_entity(ddsc_guard_cond);
}

org::eclipse::cyclonedds::core::cond::GuardConditionDelegate::~GuardConditionDelegate()
{
}

void
org::eclipse::cyclonedds::core::cond::GuardConditionDelegate::close()
{
    org::eclipse::cyclonedds::core::ScopedObjectLock scopedLock(*this);

    ConditionDelegate::close();
}


bool
org::eclipse::cyclonedds::core::cond::GuardConditionDelegate::trigger_value() const
{
    bool triggered;
    dds_return_t ret;

    org::eclipse::cyclonedds::core::ScopedObjectLock scopedLock(*this);

    this->check();
    ret = dds_read_guardcondition(this->ddsc_entity, &triggered);
    ISOCPP_DDSC_RESULT_CHECK_AND_THROW(ret, "Failed to get guard condition trigger value");

    return triggered;
}

void
org::eclipse::cyclonedds::core::cond::GuardConditionDelegate::trigger_value(bool value)
{
    dds_return_t ret;
    bool triggered;

    org::eclipse::cyclonedds::core::ScopedObjectLock scopedLock(*this);

    if (value) {
        ret = dds_set_guardcondition(this->ddsc_entity, value);
        ISOCPP_DDSC_RESULT_CHECK_AND_THROW(ret, "Failed to set guard condition trigger value");
    } else {
        ret = dds_take_guardcondition(this->ddsc_entity, &triggered);
        ISOCPP_DDSC_RESULT_CHECK_AND_THROW(ret, "Failed to reset guard condition");
    }
}
