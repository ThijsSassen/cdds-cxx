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

#ifndef CYCLONEDDS_CORE_COND_SHADOW_PARTICIPANT_HPP_
#define CYCLONEDDS_CORE_COND_SHADOW_PARTICIPANT_HPP_

#include "dds/dds.h"

#include <dds/domain/DomainParticipant.hpp>
#include <org/eclipse/cyclonedds/core/config.hpp>
#include <org/eclipse/cyclonedds/core/Mutex.hpp>
#include <org/eclipse/cyclonedds/core/ScopedLock.hpp>

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
    class ShadowParticipant {
    public:
        static ShadowParticipant& getInstance() 
        {
            org::eclipse::cyclonedds::core::ScopedMutexLock scopedLock(mutex_);
            
            if (!instance_) {
                // Create shadow participant that is used as parent entity for all waitsets
                dds_entity_t ddsc_part = dds_create_participant(DDS_DOMAIN_DEFAULT, NULL, NULL);
                instance_ = new ShadowParticipant(ddsc_part);
            }
            return *instance_;
        }

        dds_entity_t get_participant() 
        {
            return ddsc_participant_;
        }
        
    private:
        ShadowParticipant(dds_entity_t ddsc_participant) 
        {
            this->ddsc_participant_ = ddsc_participant;
        }

        ~ShadowParticipant()
        {
            dds_delete(this->ddsc_participant_);
        }
        ShadowParticipant(const ShadowParticipant&);
        ShadowParticipant& operator=(const ShadowParticipant&);

        static ShadowParticipant* instance_; 
        static org::eclipse::cyclonedds::core::Mutex mutex_;           
        dds_entity_t ddsc_participant_;
    };

}
}
}
}
}


#endif /* CYCLONEDDS_CORE_COND_SHADOW_PARTICIPANT_HPP_ */
