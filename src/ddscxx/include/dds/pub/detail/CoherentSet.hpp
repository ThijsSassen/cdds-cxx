#ifndef OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_
#define OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_

#include <dds/pub/detail/TCoherentSetImpl.hpp>
#include <org/eclipse/cyclonedds/pub/CoherentSetDelegate.hpp>

namespace dds {
	namespace pub {
		namespace detail {
			typedef dds::pub::TCoherentSet<org::eclipse::cyclonedds::pub::CoherentSetDelegate> CoherentSet;
		}
	}
}

#endif /*  OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_ */
