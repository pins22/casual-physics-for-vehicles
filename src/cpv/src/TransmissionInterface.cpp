#include "common.h"
#include <iostream>
#include "vehicle/powertrain/Transmission.h"

extern "C"
{
    DLL_EXPORT void Transmission_setFinalDriveRatio(cpv::vehicle::Transmission *transmission, double finalDriveRatio)
    {
        if (transmission)
        {

            transmission->setFinalDriveRatio(finalDriveRatio);
        }
    }

    DLL_EXPORT double Transmission_getFinalDriveRatio(cpv::vehicle::Transmission *transmission)
    {
        if (transmission)
        {
            return transmission->getFinalDriveRatio();
        }

        return -1;
    }

    DLL_EXPORT void Transmission_setCurrentGear(cpv::vehicle::Transmission *transmission, int currentGear)
    {
        if (transmission)
        {
            transmission->setCurrentGear(currentGear);
        }
    }

    DLL_EXPORT int Transmission_getCurrentGear(cpv::vehicle::Transmission *transmission)
    {
        if (transmission)
        {
            return transmission->getCurrentGear();
        }

        return -1;
    }

    DLL_EXPORT void Transmission_setGearRatios(cpv::vehicle::Transmission *transmission, double *gearRatios, int size)
    {
        if (!transmission)
            return;

        std::vector<double> gearRatiosVector;
        for (int i = 0; i < size; i++)
        {
            gearRatiosVector.push_back(gearRatios[i]);
        }
        transmission->setGearRatios(std::move(gearRatiosVector));
    }

    DLL_EXPORT void Transmission_getGearRatios(cpv::vehicle::Transmission *transmission, double** data, int *size)
    {

        const std::vector<double> &gearRatios = transmission->getGearRatios();
        *size = gearRatios.size();
        double *gearRatiosArray = static_cast<double*>(malloc(*size * sizeof(double)));
        std::copy(gearRatios.begin(), gearRatios.end(), gearRatiosArray);

        *data = gearRatiosArray;
    }
}