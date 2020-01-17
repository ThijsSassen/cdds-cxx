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
#ifndef OSPL_ORG_OPENSPICE_SUB_QUERY_DELEGATE_HPP_
#define OSPL_ORG_OPENSPICE_SUB_QUERY_DELEGATE_HPP_

/**
 * @file
 */

#include <dds/core/macros.hpp>
#include <dds/sub/Subscriber.hpp>
#include <dds/sub/AnyDataReader.hpp>

#include <org/eclipse/cyclonedds/core/DDScObjectDelegate.hpp>
#include <org/eclipse/cyclonedds/core/Mutex.hpp>


#include <vector>
#include <iterator>




namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace sub
{


class OMG_DDS_API QueryDelegate : public virtual org::eclipse::cyclonedds::core::DDScObjectDelegate
{
public:
    typedef std::vector<std::string>::iterator iterator;
    typedef std::vector<std::string>::const_iterator const_iterator;
    typedef ::dds::core::smart_ptr_traits<QueryDelegate>::ref_type Ref;
    typedef ::dds::core::smart_ptr_traits<QueryDelegate>::weak_ref_type WeakRef;

public:
    QueryDelegate(const dds::sub::AnyDataReader& dr,
                  const dds::sub::status::DataState& state_filter = dds::sub::status::DataState::any());

    QueryDelegate(const dds::sub::AnyDataReader& dr,
                  const std::string& query_expression,
                  const dds::sub::status::DataState& state_filter = dds::sub::status::DataState::any());

    QueryDelegate(const dds::sub::AnyDataReader& dr,
                  const std::string& query_expression,
                  const std::vector<std::string>& params,
                  const dds::sub::status::DataState& state_filter = dds::sub::status::DataState::any());

    virtual ~QueryDelegate();

    void init(ObjectDelegate::weak_ref_type weak_ref);

    void close();

    const std::string& expression() const;

    void expression(const std::string& expr);

    iterator begin();

    iterator end();

    const_iterator begin() const;

    const_iterator end() const;

    void add_parameter(const std::string& param);

    uint32_t parameters_length() const;

    void parameters(const std::vector<std::string>& params);

    std::vector<std::string> parameters();

    void clear_parameters();

    const dds::sub::AnyDataReader& data_reader() const;

    virtual void state_filter(dds::sub::status::DataState& s);

    virtual dds::sub::status::DataState state_filter();

    virtual bool modify_state_filter(dds::sub::status::DataState& s);

    bool state_filter_equal(dds::sub::status::DataState& s);

protected:
    void deinit();

private:
    dds::sub::AnyDataReader reader_;
    std::string expression_;
    std::vector<std::string> params_;
    dds::sub::status::DataState state_filter_;
    bool modified_;
};


}
}
}
}

#endif /* OSPL_ORG_OPENSPICE_SUB_QUERY_DELEGATE_HPP_ */
