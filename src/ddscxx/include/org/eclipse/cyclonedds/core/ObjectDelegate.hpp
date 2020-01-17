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

#ifndef CYCLONEDDS_CORE_OBJECT_DELEGATE_HPP_
#define CYCLONEDDS_CORE_OBJECT_DELEGATE_HPP_

#include "dds/core/macros.hpp"
#include "dds/core/refmacros.hpp"
#include "org/eclipse/cyclonedds/core/Mutex.hpp"

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{
class OMG_DDS_API ObjectDelegate
{
public:

    typedef ::dds::core::smart_ptr_traits< ObjectDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< ObjectDelegate >::weak_ref_type weak_ref_type;

    ObjectDelegate ();
    virtual ~ObjectDelegate ();

    virtual void close ();
    void lock() const;
    void unlock() const;

    virtual void init (ObjectDelegate::weak_ref_type weak_ref) = 0;
    ObjectDelegate::weak_ref_type get_weak_ref () const;
    ObjectDelegate::ref_type get_strong_ref () const;

protected:

    void check () const;
    void set_weak_ref (ObjectDelegate::weak_ref_type weak_ref);

    Mutex mutex;
    bool closed;
    ObjectDelegate::weak_ref_type myself;
};

}
}
}
}

#endif /* CYCLONEDDS_CORE_OBJECT_DELEGATE_HPP_ */
