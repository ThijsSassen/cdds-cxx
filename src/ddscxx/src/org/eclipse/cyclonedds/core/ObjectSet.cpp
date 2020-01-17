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

#include <org/eclipse/cyclonedds/core/ObjectSet.hpp>
#include <org/eclipse/cyclonedds/core/ScopedLock.hpp>

void
org::eclipse::cyclonedds::core::ObjectSet::insert(org::eclipse::cyclonedds::core::ObjectDelegate& obj)
{
    org::eclipse::cyclonedds::core::ScopedMutexLock scopedLock(this->mutex);
    this->objects.insert(obj.get_weak_ref());
}

void
org::eclipse::cyclonedds::core::ObjectSet::erase(org::eclipse::cyclonedds::core::ObjectDelegate& obj)
{
    org::eclipse::cyclonedds::core::ScopedMutexLock scopedLock(this->mutex);
    this->objects.erase(obj.get_weak_ref());
}

void
org::eclipse::cyclonedds::core::ObjectSet::all_close()
{
    /* Copy the objects to use them outside the lock. */
    vector vctr = this->copy();
    /* Call close() of all Objects. */
    for (vectorIterator it = vctr.begin(); it != vctr.end(); ++it) {
        org::eclipse::cyclonedds::core::ObjectDelegate::ref_type ref = it->lock();
        if (ref) {
            ref->close();
        }
    }
}

org::eclipse::cyclonedds::core::ObjectSet::vector
org::eclipse::cyclonedds::core::ObjectSet::copy()
{
    org::eclipse::cyclonedds::core::ScopedMutexLock scopedLock(this->mutex);
    vector vctr(this->objects.size());
    std::copy(this->objects.begin(), this->objects.end(), vctr.begin());
    return vctr;
}
