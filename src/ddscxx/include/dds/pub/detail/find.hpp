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

#ifndef CYCLONEDDS_DDS_PUB_DETAIL_FIND_HPP_
#define CYCLONEDDS_DDS_PUB_DETAIL_FIND_HPP_

#include <string>

#include <dds/pub/DataWriter.hpp>
#include <dds/pub/Publisher.hpp>
#include <org/eclipse/cyclonedds/pub/PublisherDelegate.hpp>
#include <org/eclipse/cyclonedds/pub/AnyDataWriterDelegate.hpp>

namespace dds
{
namespace pub
{

template <typename WRITER, typename FwdIterator>
uint32_t
find(const dds::pub::Publisher& pub, const std::string& topic_name,
     FwdIterator begin, uint32_t max_size)
{
    if(max_size > 0) {
        org::eclipse::cyclonedds::pub::AnyDataWriterDelegate::ref_type writer_base = pub.delegate()->find_datawriter(topic_name);
        if (writer_base) {
            /* Cast base writer to typed delegate: */
            typename WRITER::DELEGATE_REF_T writer_typed =
                    OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<typename WRITER::DELEGATE_T>(writer_base);
            WRITER dw(writer_typed);
            if(dw != dds::core::null)
            {
                *begin = dw;
                return 1;
            }
        }
    }
    return 0;
}


template <typename WRITER, typename BinIterator>
uint32_t
find(const dds::pub::Publisher& pub,
     const std::string& topic_name,
     BinIterator begin)
{
    org::eclipse::cyclonedds::pub::AnyDataWriterDelegate::ref_type writer_base = pub.delegate()->find_datawriter(topic_name);
    if (writer_base) {
        /* Cast base writer to typed delegate: */
        typename WRITER::DELEGATE_REF_T writer_typed =
                OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<typename WRITER::DELEGATE_T>(writer_base);
        WRITER dw(writer_typed);
        if(dw != dds::core::null)
        {
            *begin = dw;
            return 1;
        }
    }
    return 0;
}


}
}

#endif /* CYCLONEDDS_DDS_PUB_DETAIL_FIND_HPP_ */
