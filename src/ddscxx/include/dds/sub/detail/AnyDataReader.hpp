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
#ifndef CYCLONEDDS_DDS_SUB_DETAIL_ANYDATAREADER_HPP_
#define CYCLONEDDS_DDS_SUB_DETAIL_ANYDATAREADER_HPP_

#include <dds/sub/detail/TAnyDataReaderImpl.hpp>
#include <org/eclipse/cyclonedds/sub/AnyDataReaderDelegate.hpp>

namespace dds { namespace sub { namespace detail {
  typedef dds::sub::TAnyDataReader<org::eclipse::cyclonedds::sub::AnyDataReaderDelegate> AnyDataReader;
} } }

#endif /* CYCLONEDDS_DDS_SUB_DETAIL_ANYDATAREADER_HPP_ */
