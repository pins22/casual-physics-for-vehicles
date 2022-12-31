#include "common.h"
#include "MainEngine.h"

extern "C"
{
    DLL_EXPORT cpv::MainEngine *MainEngine_new()
    {
        return new cpv::MainEngine();
    }

    DLL_EXPORT void MainEngine_delete(cpv::MainEngine *mainEngine)
    {
        delete mainEngine;
    }

    DLL_EXPORT void MainEngine_initialize(cpv::MainEngine *mainEngine, const char *vehicleParametersJson)
    {
        if (mainEngine)
        {
            mainEngine->initializeVehicle(vehicleParametersJson);
        }
    }

    DLL_EXPORT cpv::Engine *MainEngine_getEngine(cpv::MainEngine *mainEngine)
    {
        if (mainEngine)
        {
            return mainEngine->getEngine().get();
        }

        return nullptr;
    }

    DLL_EXPORT cpv::Brake *MainEngine_getBrake(cpv::MainEngine *mainEngine)
    {
        if (mainEngine)
        {
            return mainEngine->getBrake().get();
        }

        return nullptr;
    }

    DLL_EXPORT cpv::Transmission *MainEngine_getTransmission(cpv::MainEngine *mainEngine)
    {
        if (mainEngine)
        {
            return mainEngine->getTransmission().get();
        }

        return nullptr;
    }

    DLL_EXPORT cpv::LongitudinalForceModel *MainEngine_getLongitudinalForceModel(cpv::MainEngine *mainEngine)
    {
        if (mainEngine)
        {
            return mainEngine->getLongitudinalForceModel().get();
        }

        return nullptr;
    }

    DLL_EXPORT double MainEngine_calculateLongitudinalForce(cpv::MainEngine *mainEngine, double velocity, double slope, double brakeAmount)
    {
        if (mainEngine)
        {
            return mainEngine->calculateLongitudinalForce(velocity, slope, brakeAmount);
        }

        return 0.0;
    }
}