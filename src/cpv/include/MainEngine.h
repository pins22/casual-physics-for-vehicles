#pragma once

#include <string>
#include <memory>

#include "vehicle/movement/LongitudinalForceModel.h"
#include "vehicle/brake/Brake.h"
#include "vehicle/powertrain/Engine.h"
#include "vehicle/powertrain/Transmission.h"
#include "core/FunctionCurve3.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace cpv
{
    using namespace vehicle;
    class MainEngine
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

        void initializeVehicle(const std::string &vehicleParametersJson);
        void initializeVehicle(const char *vehicleParametersJson);

        std::shared_ptr<Engine> getEngine();
        std::shared_ptr<Brake> getBrake();
        std::shared_ptr<Transmission> getTransmission();
        std::shared_ptr<LongitudinalForceModel> getLongitudinalForceModel();
        

    private:
        std::shared_ptr<Engine> engine;
        std::shared_ptr<Brake> brake;
        std::shared_ptr<Transmission> transmission;
        std::shared_ptr<LongitudinalForceModel> longitudinalForceModel;
    };
}
