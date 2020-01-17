#ifndef OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_
#define OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_

#include <dds/sub/detail/TGenerationCountImpl.hpp>
#include <org/eclipse/cyclonedds/sub/GenerationCountImpl.hpp>

namespace dds {
  namespace sub {
    namespace detail {
      typedef dds::sub::TGenerationCount< org::eclipse::cyclonedds::sub::GenerationCountImpl > GenerationCount;
    }
  }
}

#endif /* OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_ */
