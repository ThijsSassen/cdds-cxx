#ifndef OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_
#define OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_

#include <dds/sub/detail/TSampleInfoImpl.hpp>
#include <org/eclipse/cyclonedds/sub/SampleInfoImpl.hpp>

namespace dds { namespace sub { namespace detail {
  typedef dds::sub::TSampleInfo<org::eclipse::cyclonedds::sub::SampleInfoImpl> SampleInfo;
} } }

#endif /* OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_ */
