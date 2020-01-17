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

#include <org/eclipse/cyclonedds/core/InstanceHandleDelegate.hpp>

#include "dds/dds.h"

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{

InstanceHandleDelegate::InstanceHandleDelegate() : handle_(DDS_HANDLE_NIL)
{
    // empty
}

InstanceHandleDelegate::InstanceHandleDelegate(dds_instance_handle_t h) : handle_(h)
{
}

InstanceHandleDelegate::InstanceHandleDelegate(const dds::core::null_type& src)
    : handle_(DDS_HANDLE_NIL)
{
    (void)src;
}

InstanceHandleDelegate::~InstanceHandleDelegate() { }

InstanceHandleDelegate::InstanceHandleDelegate(const InstanceHandleDelegate& other)
    : handle_(other.handle_)
{
    this->handle_ = other.handle_;
}

dds_instance_handle_t
InstanceHandleDelegate::handle() const
{
    return handle_;
}


InstanceHandleDelegate&
InstanceHandleDelegate::operator=(const dds::core::null_type& src)
{
    (void)src;
    handle_ = DDS_HANDLE_NIL;
    return *this;
}

bool
InstanceHandleDelegate::is_nil() const
{
    return (handle_ == DDS_HANDLE_NIL);
}

bool
InstanceHandleDelegate::operator==(const InstanceHandleDelegate& that) const
{
    return (this->handle_ == that.handle_);
}

bool
InstanceHandleDelegate::operator<(const InstanceHandleDelegate& that) const
{
    return (this->handle_ < that.handle_);
}

bool
InstanceHandleDelegate::operator>(const InstanceHandleDelegate& that) const
{
    return (this->handle_ > that.handle_);
}

}
}
}
}
