#include "vehicle/movement/LongitudinalForceModel.h"
#include "vehicle/brake/Brake.h"
#include "vehicle/powertrain/Engine.h"
#include "core/FunctionCurve3.h"


#ifndef CPV_H
#define CPV_H

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

    private:
        Engine engine;
        Brake brake;
        LongitudinalForceModel longitudinalForceModel;
    };
}

#endif