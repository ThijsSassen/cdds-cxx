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

#ifndef CYCLONEDDS_CORE_ENTITY_REGISTRY_HPP_
#define CYCLONEDDS_CORE_ENTITY_REGISTRY_HPP_

#include <dds/core/detail/WeakReferenceImpl.hpp>
#include <org/eclipse/cyclonedds/core/Mutex.hpp>

#include <map>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{

template <typename T, typename U>
class EntityRegistry
{
public:
    /**
     *  @internal Inserts a EntityDelegate key, dds::core::Entity value pair into the registry.
     * @param key The org::eclipse::cyclonedds::core::Entity to use as a key
     * @param val The dds::core::Entity that encapsulates the key
     */
    void insert(T key, U& val)
    {
        mutex.lock();
        registry[key] = dds::core::WeakReference<U>(val);
        mutex.unlock();
    }

    /**
     *  @internal Removes a DDS::Entity from the registry
     * @param key Entity to remove
     */
    void remove(T key)
    {
        mutex.lock();
        registry.erase(key);
        mutex.unlock();
    }

    /**
     *  @internal Checks the registry for a dds::core::Entity that wraps the supplied DDS::Entity
     * and returns it. If no match is found dds::core::null is returned.
     * @param key DDS::Entity to find an encapsulating dds::core:Entity for.
     * @return dds::core::Entity if a match is found, dds::core::null if not.
     */
    U get(T key)
    {
        typename std::map<T, dds::core::WeakReference<U> >::iterator it;

        mutex.lock();
        it = registry.find(key);

        U entity(dds::core::null);
        if(it != registry.end())
        {
            entity = it->second.lock();
        }
        mutex.unlock();

        return entity;
    }

private:
    std::map<T, dds::core::WeakReference<U> > registry;
    org::eclipse::cyclonedds::core::Mutex mutex;
};

}
}
}
}

#endif /* CYCLONEDDS_CORE_ENTITY_REGISTRY_HPP_ */
