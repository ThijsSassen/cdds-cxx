

#include <org/eclipse/cyclonedds/core/cond/ConditionDelegate.hpp>
#include <org/eclipse/cyclonedds/core/cond/WaitSetDelegate.hpp>
#include <dds/core/cond/WaitSet.hpp>
#include <org/eclipse/cyclonedds/core/ScopedLock.hpp>
#include <org/eclipse/cyclonedds/core/ReportUtils.hpp>

#include <dds/core/cond/Condition.hpp>

#include "dds/dds.h"

org::eclipse::cyclonedds::core::cond::ConditionDelegate::ConditionDelegate() :
        myFunctor(NULL)
{
}

org::eclipse::cyclonedds::core::cond::ConditionDelegate::~ConditionDelegate()
{
    if (!this->closed) {
        try {
            DDScObjectDelegate::close();
        } catch (...) {
           /* Empty: the exception throw should have already traced an error. */
        }
    }

    // Delete functor ('this' may already be closed at this point, but make
    // sure that functor is delete here
    if (this->myFunctor) {
        delete this->myFunctor;
    }
}

void
org::eclipse::cyclonedds::core::cond::ConditionDelegate::close()
{
    DDScObjectDelegate::close();

    if (this->myFunctor) {
        delete this->myFunctor;
        this->myFunctor = NULL;
    }
}


void
org::eclipse::cyclonedds::core::cond::ConditionDelegate::init(
                                      ObjectDelegate::weak_ref_type weak_ref)
{
    /* Set weak_ref before passing ourselves to other isocpp objects. */
    this->set_weak_ref(weak_ref);
    /* Add weak_ref to the map of entities */
    this->add_to_entity_map(weak_ref);
}

void
org::eclipse::cyclonedds::core::cond::ConditionDelegate::reset_handler()
{
    if (this->myFunctor) {
        delete this->myFunctor;
        this->myFunctor = NULL;
    }
}


void
org::eclipse::cyclonedds::core::cond::ConditionDelegate::dispatch()
{
    if (this->trigger_value() && this->myFunctor)
    {
       dds::core::cond::TCondition<
                     org::eclipse::cyclonedds::core::cond::ConditionDelegate>
                                                       cond = this->wrapper();
        this->myFunctor->dispatch(cond);
    }
}

dds::core::cond::TCondition<org::eclipse::cyclonedds::core::cond::ConditionDelegate>
org::eclipse::cyclonedds::core::cond::ConditionDelegate::wrapper()
{
    org::eclipse::cyclonedds::core::cond::ConditionDelegate::ref_type ref =
          OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<ConditionDelegate>
                                                      (this->get_strong_ref());

    dds::core::cond::TCondition<org::eclipse::cyclonedds::core::cond::ConditionDelegate>
                                                                condition(ref);

    return condition;
}
