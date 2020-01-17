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

#ifndef CYCLONEDDS_CORE_INSTANCE_HANDLE_HPP_
#define CYCLONEDDS_CORE_INSTANCE_HANDLE_HPP_

#include <dds/core/types.hpp>
#include <org/eclipse/cyclonedds/core/config.hpp>
#include <dds/dds.h>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{
class InstanceHandleDelegate;
}
}
}
}

class OSPL_ISOCPP_IMPL_API org::eclipse::cyclonedds::core::InstanceHandleDelegate
{
public:
    InstanceHandleDelegate();
    InstanceHandleDelegate(dds_instance_handle_t h);
    ~InstanceHandleDelegate();
public:
    InstanceHandleDelegate(const dds::core::null_type& src);
    InstanceHandleDelegate(const InstanceHandleDelegate& other);


public:
    bool operator==(const InstanceHandleDelegate& that) const;

    bool operator<(const InstanceHandleDelegate& that) const;

    bool operator>(const InstanceHandleDelegate& that) const;

    InstanceHandleDelegate& operator=(const dds::core::null_type& src);
    bool is_nil() const;

public:
    dds_instance_handle_t handle() const;

private:
    dds_instance_handle_t handle_;
};

inline std::ostream&
operator << (std::ostream& os,
             const org::eclipse::cyclonedds::core::InstanceHandleDelegate& h)
{
    os << h.handle();
    return os;
}
#endif /* CYCLONEDDS_CORE_INSTANCE_HANDLE_HPP_ */
