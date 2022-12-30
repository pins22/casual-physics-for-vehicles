#include "common.h"
#include "vehicle/powertrain/Transmission.h"

extern "C" {
    DLL_EXPORT void Transmission_setFinalDriveRatio(cpv::vehicle::Transmission* transmission, double finalDriveRatio) {
        transmission->setFinalDriveRatio(finalDriveRatio);
    }

    DLL_EXPORT double Transmission_getFinalDriveRatio(cpv::vehicle::Transmission* transmission) {
        return transmission->getFinalDriveRatio();
    }

    DLL_EXPORT void Transmission_setCurrentGear(cpv::vehicle::Transmission* transmission, int currentGear) {
        transmission->setCurrentGear(currentGear);
    }

    DLL_EXPORT int Transmission_getCurrentGear(cpv::vehicle::Transmission* transmission) {
        return transmission->getCurrentGear();
    }

}