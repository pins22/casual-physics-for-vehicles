#pragma once

#include "core/FunctionCurve2.h"

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
             * @param lateralForceAtSlipAngle the slip angle at lateral force[N] and load[N]
             * @param lateralForceAtSlipAngleLoad the amount of load[N] at which the lateral force[N] is graphed on lateralForceAtSlipAngle
             * @param tyreForceCap the max tyre force[N]
             */
            Tyre(FunctionCurve2 lateralForceAtSlipAngle, double lateralForceAtSlipAngleLoad, double tyreForceCap);

            /**
             * @brief Get lateral force[N] at slip angle[rad] and load[N]
             *
             * @param slipAngle the slip angle[rad]
             * @param load the load[N]
             * @return double
             */
            double getLateralForce(double slipAngle, double load);

            /**
             * @brief Get wheel rotation rate[rad/s] at car speed and wheel radius[m]
             * 
             * @param carSpeed the car speed[m/s]
             * @param wheelRadius the wheel radius[m]
             * 
             * @return double
             */
            double getWheelRotationRateAtCarSpeed(double carSpeed, double wheelRadius);

            // getters
            FunctionCurve2 getLateralForceAtSlipAngle() const { return lateralForceAtSlipAngle; }
            double getLateralForceAtSlipAngleLoad() const { return lateralForceAtSlipAngleLoad; }
            double getMaxTyreForce() const { return tyreForceCap; }

            // setters
            void setLateralForceAtSlipAngle(FunctionCurve2 lateralForceAtSlipAngle) { this->lateralForceAtSlipAngle = lateralForceAtSlipAngle; }
            void setLateralForceAtSlipAngleLoad(double lateralForceAtSlipAngleLoad) { this->lateralForceAtSlipAngleLoad = lateralForceAtSlipAngleLoad; }
            void setMaxTyreForce(double tyreForceCap) { this->tyreForceCap = tyreForceCap; }

        private:
            // vehicle specific constants
            FunctionCurve2 lateralForceAtSlipAngle; // lateralForceAtSlipAngle is the slip angle[rad] at lateral force[N] and load[N]
            double lateralForceAtSlipAngleLoad;      // amount of load[N] at which the lateral force[N] is graphed on lateralForceAtSlipAngle

            double tyreForceCap; // tyreForceCap is the max tyre force[N]
        };
    }
}