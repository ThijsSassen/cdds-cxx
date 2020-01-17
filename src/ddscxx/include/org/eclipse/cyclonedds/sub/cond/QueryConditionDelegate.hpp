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

#ifndef CYCLONEDDS_SUB_COND_QUERYCONDITION_DELEGATE_HPP_
#define CYCLONEDDS_SUB_COND_QUERYCONDITION_DELEGATE_HPP_

#include <org/eclipse/cyclonedds/sub/cond/ReadConditionDelegate.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace sub
{
namespace cond
{

class OMG_DDS_API QueryConditionDelegate :
    public org::eclipse::cyclonedds::sub::cond::ReadConditionDelegate
{
public:

    typedef QueryDelegate::iterator iterator;
    typedef QueryDelegate::const_iterator const_iterator;

public:
    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const std::string& query_expression,
            const dds::sub::status::DataState& state_filter);

    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const std::string& expression,
            const std::vector<std::string>& params,
            const dds::sub::status::DataState& data_state);

    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const dds::sub::status::DataState& data_state);

    template<typename FUN>
    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const std::string& expression,
            const dds::sub::status::DataState& data_state,
            const FUN& functor) :
                QueryDelegate(dr, expression, data_state),
                ReadConditionDelegate(dr, data_state)
    {
        this->set_handler<FUN>(functor);
    }

    template<typename FUN>
    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const std::string& expression,
            const std::vector<std::string>& params,
            const dds::sub::status::DataState& data_state,
            const FUN& functor) :
                QueryDelegate(dr, expression, params, data_state),
                ReadConditionDelegate(dr, data_state)
    {
        this->set_handler<FUN>(functor);
    }

    ~QueryConditionDelegate();

    typedef bool (*Filter_fn) (const void * sample);

    void set_filter(Filter_fn filter);

    Filter_fn get_filter();

    void init(ObjectDelegate::weak_ref_type weak_ref);
protected:
    Filter_fn cpp_filter;

    static bool trans_filter(const void *csample, const void *ctx);
};

}
}
}
}
}

#endif /* CYCLONEDDS_SUB_COND_QUERYCONDITION_DELEGATE_HPP_ */
