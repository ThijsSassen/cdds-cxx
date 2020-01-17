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

#ifndef CYCLONEDDS_CORE_SCOPEDLOCK_HPP_
#define CYCLONEDDS_CORE_SCOPEDLOCK_HPP_

#include <org/eclipse/cyclonedds/core/Mutex.hpp>
#include <org/eclipse/cyclonedds/core/ObjectDelegate.hpp>

#include <cassert>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{

template <typename LOCKABLE>
class OMG_DDS_API ScopedLock
{
public:
    ScopedLock(const LOCKABLE& obj, bool lock = true)
        : lockable(obj),
          owner(lock)
    {
        if (lock) {
            lockable.lock();
        }
    }

    virtual ~ScopedLock()
    {
        if (owner) {
            try {
                lockable.unlock();
            } catch (...) {
                /* Don't know what to do anymore (it should have never failed)... */
                assert(false);
            }
        }
    }

    void lock()
    {
        assert(!owner);
        lockable.lock();
        owner = true;
    }

    bool try_lock()
    {
        bool locked;
        locked = lockable.try_lock();
        if (locked) {
            owner = true;
        }
        return locked;
    }

    void unlock()
    {
        assert(owner);
        owner = false;
        lockable.unlock();
    }

    bool own() const
    {
        return owner;
    }

private:
    const LOCKABLE& lockable;
    bool owner;
};

typedef ScopedLock<Mutex> ScopedMutexLock;
typedef ScopedLock<ObjectDelegate> ScopedObjectLock;

}
}
}
}


#endif /* CYCLONEDDS_CORE_SCOPEDLOCK_HPP_ */
