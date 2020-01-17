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
#include "org/eclipse/cyclonedds/core/ObjectDelegate.hpp"
#include <org/eclipse/cyclonedds/core/ReportUtils.hpp>

org::eclipse::cyclonedds::core::ObjectDelegate::ObjectDelegate () :
  closed (false)
{
}

org::eclipse::cyclonedds::core::ObjectDelegate::~ObjectDelegate ()
{
}

void org::eclipse::cyclonedds::core::ObjectDelegate::check () const
{
  /* This method is not-thread-safe, and should only be used with a lock. */
  if (closed) {
    ISOCPP_THROW_EXCEPTION (ISOCPP_ALREADY_CLOSED_ERROR, "Trying to invoke an oparation on an object that was already closed");
  }
}

void org::eclipse::cyclonedds::core::ObjectDelegate::lock () const
{
  this->mutex.lock ();
  try
  {
    check();
  }
  catch (...)
  {
    this->mutex.unlock ();
    throw;
  }
}

void org::eclipse::cyclonedds::core::ObjectDelegate::unlock () const
{
  this->mutex.unlock ();
}

void org::eclipse::cyclonedds::core::ObjectDelegate::close ()
{
  this->closed = true;
}

void org::eclipse::cyclonedds::core::ObjectDelegate::set_weak_ref (ObjectDelegate::weak_ref_type weak_ref)
{
  this->myself = weak_ref;
}

org::eclipse::cyclonedds::core::ObjectDelegate::weak_ref_type
org::eclipse::cyclonedds::core::ObjectDelegate::get_weak_ref () const
{
  return this->myself;
}

org::eclipse::cyclonedds::core::ObjectDelegate::ref_type
org::eclipse::cyclonedds::core::ObjectDelegate::get_strong_ref () const
{
  return this->myself.lock ();
}
