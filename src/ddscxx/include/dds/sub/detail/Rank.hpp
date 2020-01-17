#ifndef OMG_DDS_SUB_DETAIL_RANK_HPP
#define OMG_DDS_SUB_DETAIL_RANK_HPP

#include <dds/sub/detail/TRankImpl.hpp>
#include <org/eclipse/cyclonedds/sub/RankImpl.hpp>

namespace dds { namespace sub { namespace detail {
  typedef dds::sub::TRank< org::eclipse::cyclonedds::sub::RankImpl > Rank;
} } }

#endif /* OMG_DDS_SUB_DETAIL_RANK_HPP */
