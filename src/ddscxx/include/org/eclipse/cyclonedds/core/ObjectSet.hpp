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

#ifndef CYCLONEDDS_CORE_OBJECT_SET_HPP_
#define CYCLONEDDS_CORE_OBJECT_SET_HPP_

#include <dds/core/InstanceHandle.hpp>

#include <org/eclipse/cyclonedds/core/ObjectDelegate.hpp>
#include <org/eclipse/cyclonedds/core/Mutex.hpp>
#include <org/eclipse/cyclonedds/core/WeakReferenceSet.hpp>

#include <vector>
#include <memory>
#include <set>


namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{

class ObjectSet
{
public:
    typedef std::set<org::eclipse::cyclonedds::core::ObjectDelegate::weak_ref_type>::iterator    setIterator;
    typedef std::vector<org::eclipse::cyclonedds::core::ObjectDelegate::weak_ref_type>::iterator vectorIterator;
    typedef std::vector<org::eclipse::cyclonedds::core::ObjectDelegate::weak_ref_type>           vector;

    /**
     *  @internal Inserts a EntityDelegate into the set.
     * @param entity The org::eclipse::cyclonedds::core::ObjectDelegate to store
     */
    void insert(org::eclipse::cyclonedds::core::ObjectDelegate& obj);

    /**
     *  @internal Erases a EntityDelegate from the set.
     * @param entity The org::eclipse::cyclonedds::core::ObjectDelegate to delete
     */
    void erase(org::eclipse::cyclonedds::core::ObjectDelegate& obj);

    /**
     *  @internal Call close() of all the Objects within the set (outside lock).
     */
    void all_close();

    /**
     *  @internal Copy internal set into a vector.
     */
    vector copy();

private:
    WeakReferenceSet<ObjectDelegate::weak_ref_type>::wset objects;
    Mutex mutex;
};

}
}
}
}

#endif /* CYCLONEDDS_CORE_OBJECT_SET_HPP_ */
