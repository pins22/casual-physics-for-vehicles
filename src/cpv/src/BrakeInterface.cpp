#include "common.h"
#include "vehicle/brake/Brake.h"

extern "C" {
    void DLL_EXPORT Brake_setMaxBrakeTorque(cpv::vehicle::Brake* brake, double maxBrakeTorque) {
        if(brake) {
            brake->setMaxBrakeTorque(maxBrakeTorque);
        }
    }

    double DLL_EXPORT Brake_getMaxBrakeTorque(cpv::vehicle::Brake* brake) {
        if (brake){
            return brake->getMaxBrakeTorque();
        }

        return -1;
    }
}