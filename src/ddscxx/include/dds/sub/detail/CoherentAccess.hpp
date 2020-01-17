#ifndef OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_
#define OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_

#include <dds/sub/detail/TCoherentAccessImpl.hpp>
#include <org/eclipse/cyclonedds/sub/CoherentAccessDelegate.hpp>

namespace dds { namespace sub { namespace detail {
  typedef ::dds::sub::TCoherentAccess<org::eclipse::cyclonedds::sub::CoherentAccessDelegate> CoherentAccess;
} } }

#endif /* OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_ */
