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
#ifndef CYCLONEDDS_DDS_SUB_DETAIL_QUERY_IMPL_HPP_
#define CYCLONEDDS_DDS_SUB_DETAIL_QUERY_IMPL_HPP_

/**
 * @file
 */

// Implementation
#include <dds/sub/TQuery.hpp>

template <typename DELEGATE>
dds::sub::TQuery<DELEGATE>::TQuery(
    const dds::sub::AnyDataReader& dr,
    const std::string& expression) :
        dds::core::Reference<DELEGATE>(new DELEGATE(AnyDataReader(dr), expression))
{
}

template <typename DELEGATE>
template<typename FWIterator>
dds::sub::TQuery<DELEGATE>::TQuery(
    const dds::sub::AnyDataReader& dr,
    const std::string& expression,
    const FWIterator& params_begin,
    const FWIterator& params_end) :
        dds::core::Reference<DELEGATE>(new DELEGATE(AnyDataReader(dr), expression))
{
    for (FWIterator it = params_begin; it != params_end; ++it) {
        add_parameter(*it);
    }
}

template <typename DELEGATE>
dds::sub::TQuery<DELEGATE>::TQuery(
    const dds::sub::AnyDataReader& dr,
    const std::string& expression,
    const std::vector<std::string>& params) :
        dds::core::Reference<DELEGATE>(new DELEGATE(AnyDataReader(dr), expression, params))
{

}

template <typename DELEGATE>
const std::string& dds::sub::TQuery<DELEGATE>::expression() const
{
    return this->delegate()->expression();
}

template <typename DELEGATE>
void dds::sub::TQuery<DELEGATE>::expression(const std::string& expr)
{
    this->delegate()->expression(expr);
}

/**
 * Provides the begin iterator to the parameter list.
 */
template <typename DELEGATE>
typename dds::sub::TQuery<DELEGATE>::const_iterator dds::sub::TQuery<DELEGATE>::begin() const
{
    return this->delegate()->begin();
}

/**
 * The end iterator to the parameter list.
 */
template <typename DELEGATE>
typename dds::sub::TQuery<DELEGATE>::const_iterator dds::sub::TQuery<DELEGATE>::end() const
{
    return this->delegate()->end();
}

/**
 * Provides the begin iterator to the parameter list.
 */
template <typename DELEGATE>
typename dds::sub::TQuery<DELEGATE>::iterator dds::sub::TQuery<DELEGATE>::begin()
{
    return this->delegate()->begin();
}

/**
 * The end iterator to the parameter list.
 */
template <typename DELEGATE>
typename dds::sub::TQuery<DELEGATE>::iterator dds::sub::TQuery<DELEGATE>::end()
{
    return this->delegate()->end();
}

template <typename DELEGATE>
template<typename FWIterator>
void dds::sub::TQuery<DELEGATE>::parameters(
    const FWIterator& begin,
    const FWIterator end)
{
    for (FWIterator it = begin; it != end; ++it) {
        add_parameter(*it);
    }
}

template <typename DELEGATE>
void dds::sub::TQuery<DELEGATE>::add_parameter(
    const std::string& param)
{
    this->delegate()->add_parameter(param);
}

template <typename DELEGATE>
uint32_t dds::sub::TQuery<DELEGATE>::parameters_length() const
{
    return this->delegate()->parameters_length();
}

template <typename DELEGATE>
const dds::sub::AnyDataReader&
dds::sub::TQuery<DELEGATE>::data_reader() const
{
    return this->delegate()->data_reader();
}




#endif /* CYCLONEDDS_DDS_SUB_DETAIL_QUERY_IMPL_HPP_ */
