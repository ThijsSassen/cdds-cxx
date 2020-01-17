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

#ifndef CYCLONEDDS_CORE_STATUS_CONDITION_DELEGATE_HPP_
#define CYCLONEDDS_CORE_STATUS_CONDITION_DELEGATE_HPP_

#include <dds/core/Entity.hpp>
#include <dds/core/status/Status.hpp>
#include <org/eclipse/cyclonedds/core/cond/ConditionDelegate.hpp>

namespace dds
{
namespace core
{
namespace cond
{
template <typename T> class TStatusCondition;
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

class OMG_DDS_API StatusConditionDelegate :
                         public org::eclipse::cyclonedds::core::cond::ConditionDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits<StatusConditionDelegate>::ref_type
                                                                      ref_type;
    typedef
       ::dds::core::smart_ptr_traits<StatusConditionDelegate>::weak_ref_type
                                                                 weak_ref_type;

    StatusConditionDelegate(
            const org::eclipse::cyclonedds::core::EntityDelegate *entity,
            dds_entity_t uEntity);

    ~StatusConditionDelegate();

    virtual void close();

    void init(org::eclipse::cyclonedds::core::ObjectDelegate::weak_ref_type weak_ref);

    void enabled_statuses(const dds::core::status::StatusMask& status);

    dds::core::status::StatusMask enabled_statuses() const;

    dds::core::Entity& entity();

    virtual bool trigger_value() const;

    dds::core::cond::TStatusCondition<StatusConditionDelegate> wrapper();

private:
    dds::core::Entity myEntity;
};

}
}
}
}
}

#endif  /* CYCLONEDDS_CORE_STATUS_CONDITION_DELEGATE_HPP_ */
