#pragma once

#include <string>
#include <memory>

#include "vehicle/movement/LongitudinalForceModel.h"
#include "vehicle/brake/Brake.h"
#include "vehicle/powertrain/Engine.h"
#include "core/FunctionCurve3.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#ifdef _MSC_VER
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

namespace cpv
{
    using namespace vehicle;
    class DLL_EXPORT MainEngine
    {
    public:
        /**
         * @brief Construct a new Main Engine object with default values
         */
        MainEngine();

        /**
         * @brief Construct a new Main Engine object
         * 
         * @param vehicleParameters the vehicle parameters
         */

        /*
        * TODO:
        * initialize vehicle method (json) 
        * get and setters for vehicle parameters
        * calculate longitudinal force method  (velocity, slope, breaking amount)
        * calculate lateral force method 
        */

       void initializeVehicle(const std::string& vehicleParametersJson);
       void initializeVehicle(const char* vehicleParametersJson);

       std::shared_ptr<Engine> getEngine();

    private:
        std::shared_ptr<Engine> engine;
        std::shared_ptr<Brake> brake;
        std::shared_ptr<LongitudinalForceModel> longitudinalForceModel;

    };
}

extern "C" {
    DLL_EXPORT cpv::MainEngine* MainEngine_new(){
        return new cpv::MainEngine();
    }

    DLL_EXPORT void MainEngine_delete(cpv::MainEngine* mainEngine) {
        delete mainEngine;
    } 

    DLL_EXPORT void MainEngine_initialize(cpv::MainEngine* mainEngine, const char* vehicleParametersJson){
        mainEngine->initializeVehicle(vehicleParametersJson);
    }

    DLL_EXPORT cpv::Engine* MainEngine_getEngine(cpv::MainEngine* mainEngine){
        return mainEngine->getEngine().get();
    }

}