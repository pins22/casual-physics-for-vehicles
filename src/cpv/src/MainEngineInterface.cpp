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
}