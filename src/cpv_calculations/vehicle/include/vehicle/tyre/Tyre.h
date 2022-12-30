#pragma once

#include "core/FunctionCurve3.h"

namespace cpv
{
    namespace vehicle
    {
        class Tyre
        {
        public:
            /**
             * @brief Default constructor for the Tyre class
             * @details Sets all values to 0
             */
            Tyre();

            /**
             * @brief Basic constructor for the Tyre class
             * @details Sets all values to the given values
             *
             * @param maxTyreForce the max tyre force[N]
             * @param slipAngleAtLateralForceAndLoad the slip angle at lateral force[N] and load[N]
             */
            Tyre(FunctionCurve3 slipAngleAtLateralForceAndLoad);

            /**
             * @brief Get lateral force[N] at slip angle[rad] and load[N]
             * 
             * @param slipAngle the slip angle[rad]
             * @param load the load[N]
             * @return double 
             */
            double getLateralForce(double slipAngle, double load);


        private:
            // vehicle specific constants
            FunctionCurve3 slipAngleAtLateralForceAndLoad; // slipAngleAtLateralForceAndLoad is the slip angle[rad] at lateral force[N] and load[N]
        };
    }
}