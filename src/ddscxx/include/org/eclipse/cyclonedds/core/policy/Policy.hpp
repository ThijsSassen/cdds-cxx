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


/**
 * @file
 */

#ifndef CYCLONEDDS_CORE_POLICY_POLICY_HPP_
#define CYCLONEDDS_CORE_POLICY_POLICY_HPP_


/******************************************************************************
 *
 * PROPRIETARY POLICIES
 *
 ******************************************************************************/

#include <org/eclipse/cyclonedds/core/policy/PolicyDelegate.hpp>
#include <org/eclipse/cyclonedds/core/policy/TPolicy.hpp>


/* Use same macro as in dds/core/policy/CorePolicy.hpp, called OMG_DDS_POLICY_TRAITS */
#define LITE_POLICY_TRAITS(POLICY, ID) \
    template <> \
    class policy_id<POLICY> { \
    public: \
        static const dds::core::policy::QosPolicyId value = ID; \
    };\
    template <> \
    class policy_name<POLICY> { \
    public:\
        static const std::string& name(); \
    };

namespace dds
{
namespace core
{
namespace policy
{
template <typename Policy>
class policy_id;
template <typename Policy>
class policy_name;
}
}
}


#undef LITE_POLICY_TRAITS

#endif /* CYCLONEDDS_CORE_POLICY_POLICY_HPP_ */
