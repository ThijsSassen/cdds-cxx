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

#ifndef CYCLONEDDS_CORE_COND_WAITSET_DELEGATE_HPP_
#define CYCLONEDDS_CORE_COND_WAITSET_DELEGATE_HPP_

#include <vector>
#include <map>

#include <dds/core/Duration.hpp>
#include <dds/core/cond/Condition.hpp>
#include <org/eclipse/cyclonedds/core/config.hpp>
#include <org/eclipse/cyclonedds/core/DDScObjectDelegate.hpp>

namespace dds
{
  namespace core
  {
    namespace cond
    {
      template <typename DELEGATE> class TWaitSet;
    }
  }
}

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace core
{
namespace cond
{
    class OMG_DDS_API WaitSetDelegate :
        public org::eclipse::cyclonedds::core::DDScObjectDelegate
    {
    public:

        typedef ::dds::core::smart_ptr_traits< WaitSetDelegate >::ref_type ref_type;
        typedef ::dds::core::smart_ptr_traits< WaitSetDelegate >::weak_ref_type weak_ref_type;
        typedef std::vector<dds::core::cond::Condition> ConditionSeq;
        typedef std::map<org::eclipse::cyclonedds::core::cond::ConditionDelegate *,
                dds::core::cond::Condition> ConditionMap;

        typedef std::map<org::eclipse::cyclonedds::core::cond::ConditionDelegate *,
                dds::core::cond::Condition>::iterator ConditionIterator;

        typedef std::map<org::eclipse::cyclonedds::core::cond::ConditionDelegate *,
                dds::core::cond::Condition>::const_iterator ConstConditionIterator;

        typedef std::pair<org::eclipse::cyclonedds::core::cond::ConditionDelegate *,
                dds::core::cond::Condition> ConditionEntry;

        WaitSetDelegate ();
        virtual ~WaitSetDelegate ();

        void init (ObjectDelegate::weak_ref_type weak_ref);
        void close ();

        ConditionSeq& wait (ConditionSeq& triggered, const dds::core::Duration& timeout);

        void dispatch (const dds::core::Duration & timeout);

        void attach_condition (const dds::core::cond::Condition & cond);
        bool detach_condition (org::eclipse::cyclonedds::core::cond::ConditionDelegate * cond);
        ConditionSeq & conditions (ConditionSeq & conds) const;

    private:
        ConditionMap conditions_;
    };
}
}
}
}
}

#ifdef _WIN32
#pragma warning ( pop )
#endif

#endif /* CYCLONEDDS_CORE_COND_WAITSET_DELEGATE_HPP_ */
