#include "common.h"
#include "vehicle/brake/Brake.h"

extern "C"
{

    DLL_EXPORT cpv::vehicle::Brake *Brake_new()
    {
        return new cpv::vehicle::Brake();
    }

    DLL_EXPORT void Brake_delete(cpv::vehicle::Brake *brake)
    {
        delete brake;
    }

    DLL_EXPORT void Brake_setMaxBrakeTorque(cpv::vehicle::Brake *brake, double maxBrakeTorque)
    {
        if (brake)
        {
            brake->setMaxBrakeTorque(maxBrakeTorque);
        }
    }

    DLL_EXPORT double Brake_getMaxBrakeTorque(cpv::vehicle::Brake *brake)
    {
        if (brake)
        {
            return brake->getMaxBrakeTorque();
        }

        return -1;
    }
}