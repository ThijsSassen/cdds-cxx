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
#ifndef CYCLONEDDS_DDS_TOPIC_DETAIL_FILTER_HPP_
#define CYCLONEDDS_DDS_TOPIC_DETAIL_FILTER_HPP_

/**
 * @file
 */

// Implementation

#include <string>
#include <vector>
#include <iterator>

#include <dds/core/detail/inttypes.hpp>
#include <dds/core/macros.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace topic
{
class OMG_DDS_API FilterDelegate
{
public:
    typedef std::vector<std::string>::iterator iterator;
    typedef std::vector<std::string>::const_iterator const_iterator;

public:
    FilterDelegate();
    FilterDelegate(const std::string& query_expression);


    template <typename FWIterator>
    FilterDelegate(const std::string& query_expression,
           const FWIterator& params_begin, const FWIterator& params_end)
               : myExpression(query_expression)
    {
        std::copy(params_begin, params_end, std::back_insert_iterator<std::vector<std::string> >(myParams));
    }

    const std::string& expression() const;

    /**
    *  @internal Provides the begin iterator to the parameter list.
    */
    const_iterator begin() const;

    /**
     *  @internal The const end iterator to the parameter list.
     */
    const_iterator end() const;

    /**
     *  @internal Provides the begin const iterator to the parameter list.
     */
    iterator begin();

    /**
     *  @internal The end iterator to the parameter list.
     */
    iterator end();

    template <typename FWIterator>
    void parameters(const FWIterator& begin, const FWIterator end)
    {
        myParams.erase(myParams.begin(), myParams.end());
        std::copy(begin, end, std::back_insert_iterator<std::vector<std::string> >(myParams));
    }

    void add_parameter(const std::string& param);

    uint32_t parameters_length() const;

    bool operator ==(const FilterDelegate& other) const;

private:
    std::string myExpression;
    std::vector<std::string> myParams;
};


// End of implementation
}
}
}
}

#endif /* CYCLONEDDS_DDS_TOPIC_DETAIL_FILTER_HPP_ */
