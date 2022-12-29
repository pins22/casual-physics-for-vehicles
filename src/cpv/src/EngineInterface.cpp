#include "common.h"
#include "vehicle/powertrain/Engine.h"

extern "C" {
    void DLL_EXPORT Engine_setIdleRpm(cpv::vehicle::Engine* engine, int idleRpm) {
        if(engine) {
            engine->setIdleRpm(idleRpm);
        }
    }

    int DLL_EXPORT Engine_getIdleRpm(cpv::vehicle::Engine* engine) {
        if (engine){
            return engine->getIdleRpm();
        }

        return -1;
    }

    void DLL_EXPORT Engine_setMaxRpm(cpv::vehicle::Engine* engine, int maxRpm) {
        if(engine) {
            engine->setMaxRpm(maxRpm);
        }
    }

    int DLL_EXPORT Engine_getMaxRpm(cpv::vehicle::Engine* engine) {
        if (engine){
            return engine->getMaxRpm();
        }

        return -1;
    }

    void DLL_EXPORT Engine_setRpm(cpv::vehicle::Engine* engine, int rpm) {
        if(engine) {
            engine->setRpm(rpm);
        }
    }

    int DLL_EXPORT Engine_getRpm(cpv::vehicle::Engine* engine) {
        if (engine){
            return engine->getRpm();
        }

        return -1;
    }

    void DLL_EXPORT Engine_setThrottle(cpv::vehicle::Engine* engine, double throttle) {
        if(engine) {
            engine->setThrottle(throttle);
        }
    }

    double DLL_EXPORT Engine_getThrottle(cpv::vehicle::Engine* engine) {
        if (engine){
            return engine->getThrottle();
        }

        return -1;
    }
}