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
#ifndef OMG_DDS_PUB_DETAIL_ANYDATAWRITER_HPP_
#define OMG_DDS_PUB_DETAIL_ANYDATAWRITER_HPP_

#include <dds/pub/detail/TAnyDataWriterImpl.hpp>
#include <org/eclipse/cyclonedds/pub/AnyDataWriterDelegate.hpp>

namespace dds { namespace pub { namespace detail {
  typedef dds::pub::TAnyDataWriter<org::eclipse::cyclonedds::pub::AnyDataWriterDelegate> AnyDataWriter;
} } }

#endif /* OMG_DDS_PUB_DETAIL_ANYDATAWRITER_HPP_ */
