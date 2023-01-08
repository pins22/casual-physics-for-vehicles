#include "vehicle/tyre/Tyre.h"
#include "core/FunctionCurve2.h"

namespace cpv
{
    namespace vehicle
    {
        FunctionCurve2 lateralForceAtSlipAngle; // lateralForceAtSlipAngle is the slip angle[rad] at lateral force[N] and load[N]
        double lateralForceAtSlipAngleLoad;     // amount of load[N] at which the lateral force[N] is graphed on lateralForceAtSlipAngle
        double tyreForceCap;                    // tyreForceCap is the max tyre force[N]

        Tyre::Tyre()
        {
            // vehicle specific constants
            FunctionCurve2 lateralForceAtSlipAngle; // lateralForceAtSlipAngle is the slip angle[rad] at lateral force[N] and load[N]
            double lateralForceAtSlipAngleLoad;      // amount of load[N] at which the lateral force[N] is graphed on lateralForceAtSlipAngle
            double tyreForceCap;                     // tyreForceCap is the max tyre force[N]
        }

        Tyre::Tyre(FunctionCurve2 lateralForceAtSlipAngle, double lateralForceAtSlipAngleLoad, double tyreForceCap)
        {
            // vehicle specific constants
            this->lateralForceAtSlipAngle = lateralForceAtSlipAngle; // lateralForceAtSlipAngle is the slip angle[rad] at lateral force[N] and load[N]
            this->lateralForceAtSlipAngleLoad = lateralForceAtSlipAngleLoad;                   // amount of load[N] at which the lateral force[N] is graphed on lateralForceAtSlipAngle
            this->tyreForceCap = tyreForceCap;                       // tyreForceCap is the max tyre force[N]
        }

        double Tyre::getLateralForce(double slipAngle, double load)
        {
            // here the force is linear to the load
            return lateralForceAtSlipAngle.getYValue(slipAngle) * load / lateralForceAtSlipAngleLoad;
        }

        double Tyre::getWheelRotationRateAtCarSpeed(double carSpeed, double wheelRadius)
        {
            return carSpeed / wheelRadius;
        }

        // getters
        FunctionCurve2 Tyre::getLateralForceAtSlipAngle() { return lateralForceAtSlipAngle; }
        double Tyre::getLateralForceAtSlipAngleLoad() { return lateralForceAtSlipAngleLoad; }
        double Tyre::getMaxTyreForce() { return tyreForceCap; }

        // setters
        void Tyre::setLateralForceAtSlipAngle(FunctionCurve2 lateralForceAtSlipAngle) { this->lateralForceAtSlipAngle = lateralForceAtSlipAngle; }
        void Tyre::setLateralForceAtSlipAngleLoad(double lateralForceAtSlipAngleLoad) { this->lateralForceAtSlipAngleLoad = lateralForceAtSlipAngleLoad; }
        void Tyre::setMaxTyreForce(double tyreForceCap) { this->tyreForceCap = tyreForceCap; }
    }
}
