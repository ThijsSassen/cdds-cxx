/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2014 PrismTech
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

#ifndef CYCLONEDDS_CORE_USEROBJECT_DELEGATE_HPP_
#define CYCLONEDDS_CORE_USEROBJECT_DELEGATE_HPP_

#include "dds/core/macros.hpp"
#include "dds/core/refmacros.hpp"
#include "org/eclipse/cyclonedds/core/Mutex.hpp"
#include "org/eclipse/cyclonedds/core/ObjectDelegate.hpp"

#include <unordered_map>

#include "dds/dds.h"

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{
class OMG_DDS_API DDScObjectDelegate : public virtual org::eclipse::cyclonedds::core::ObjectDelegate
{
public:

    typedef std::unordered_map<dds_entity_t,org::eclipse::cyclonedds::core::ObjectDelegate::weak_ref_type> entity_map_type;

    DDScObjectDelegate ();
    virtual ~DDScObjectDelegate ();

    void close ();
    dds_entity_t get_ddsc_entity ();
    void set_ddsc_entity (dds_entity_t e);
    void add_to_entity_map (org::eclipse::cyclonedds::core::ObjectDelegate::weak_ref_type weak_ref);

public:
    static ObjectDelegate::ref_type extract_strong_ref(dds_entity_t e);

protected:
    dds_entity_t ddsc_entity;

private:
    void delete_from_entity_map();
    static org::eclipse::cyclonedds::core::DDScObjectDelegate::entity_map_type entity_map;
    static Mutex entity_map_mutex;
};
}
}
}
}

#endif /* CYCLONEDDS_CORE_USEROBJECT_DELEGATE_HPP_ */
