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

#ifndef CYCLONEDDS_SUB_COHERENT_ACCESS_DELEGATE_HPP_
#define CYCLONEDDS_SUB_COHERENT_ACCESS_DELEGATE_HPP_

#include <dds/sub/Subscriber.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace sub
{

class OMG_DDS_API CoherentAccessDelegate
{
public:
    CoherentAccessDelegate(const dds::sub::Subscriber sub);
    ~CoherentAccessDelegate();

    void end();

    bool operator==(const CoherentAccessDelegate& other) const;

private:
    dds::sub::Subscriber sub;
    bool ended;
};

}
}
}
}

#endif /* CYCLONEDDS_SUB_COHERENT_ACCESS_DELEGATE_HPP_ */
