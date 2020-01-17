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
#ifndef CYCLONEDDS_DDS_TOPIC_TCONTENTFILTEREDTOPIC_HPP_
#define CYCLONEDDS_DDS_TOPIC_TCONTENTFILTEREDTOPIC_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/topic/TContentFilteredTopic.hpp>

// Implementation

namespace dds
{
namespace topic
{
template <typename T, template <typename Q> class DELEGATE>
ContentFilteredTopic<T, DELEGATE>::ContentFilteredTopic(const Topic<T>& topic,
                                                        const std::string& name,
                                                        const dds::topic::Filter& filter) :
        ::dds::core::Reference< DELEGATE<T> >(
                new dds::topic::detail::ContentFilteredTopic<T>(topic, name, filter))
{
    this->delegate()->init(::dds::core::Reference< DELEGATE<T> >::impl_);
}

template <typename T, template <typename Q> class DELEGATE>
ContentFilteredTopic<T, DELEGATE>::~ContentFilteredTopic()
{
    // Nothing to be done yet....
}

template <typename T, template <typename Q> class DELEGATE>
const std::string& ContentFilteredTopic<T, DELEGATE>::filter_expression() const
{
    return this->delegate()->filter_expression();
}

template <typename T, template <typename Q> class DELEGATE>
const dds::core::StringSeq ContentFilteredTopic<T, DELEGATE>::filter_parameters() const
{
    return this->delegate()->filter_parameters();
}

template <typename T, template <typename Q> class DELEGATE>
template <typename FWDIterator>
void ContentFilteredTopic<T, DELEGATE>::filter_parameters(const FWDIterator& begin, const FWDIterator& end)
{
    this->delegate()->filter_parameters(begin, end);
}

template <typename T, template <typename Q> class DELEGATE>
const dds::topic::Topic<T>& ContentFilteredTopic<T, DELEGATE>::topic() const
{
    return this->delegate()->topic();
}


}
}

// End of implementation

#endif /* CYCLONEDDS_DDS_TOPIC_TCONTENTFILTEREDTOPIC_HPP_ */
