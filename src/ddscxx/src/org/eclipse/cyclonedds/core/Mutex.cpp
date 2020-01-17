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

#include <org/eclipse/cyclonedds/core/Mutex.hpp>
#include "dds/dds.h"
#include "dds/ddsrt/sync.h"

org::eclipse::cyclonedds::core::Mutex::Mutex()
{
  mtx = dds_alloc (sizeof (ddsrt_mutex_t));
  ddsrt_mutex_init ((ddsrt_mutex_t*)this->mtx);
}

org::eclipse::cyclonedds::core::Mutex::~Mutex()
{
  ddsrt_mutex_destroy ((ddsrt_mutex_t*)this->mtx);
  dds_free (mtx);
}

void org::eclipse::cyclonedds::core::Mutex::lock() const
{
  ddsrt_mutex_lock ((ddsrt_mutex_t*) this->mtx);
}

bool org::eclipse::cyclonedds::core::Mutex::try_lock () const
{
  return (ddsrt_mutex_trylock ((ddsrt_mutex_t*) this->mtx));
}

void org::eclipse::cyclonedds::core::Mutex::unlock() const
{
  ddsrt_mutex_unlock ((ddsrt_mutex_t*) this->mtx);
}
