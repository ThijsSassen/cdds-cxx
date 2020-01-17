/*
 * Query.hpp
 *
 *  Created on: Oct 10, 2012
 *      Author: angelo
 */

#ifndef DDS_SUB_DETAIL_QUERY_HPP_
#define DDS_SUB_DETAIL_QUERY_HPP_

#include <dds/sub/TQuery.hpp>
#include <org/eclipse/cyclonedds/sub/QueryDelegate.hpp>


namespace dds
{
namespace sub
{
namespace detail
{
typedef dds::sub::TQuery<org::eclipse::cyclonedds::sub::QueryDelegate> Query;
}
}
}


#endif /* DDS_SUB_DETAIL_QUERY_HPP_ */
