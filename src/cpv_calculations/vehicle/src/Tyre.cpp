#include "vehicle/tyre/Tyre.h"
#include "core/FunctionCurve3.h"

namespace cpv
{
    namespace vehicle
    {
        Tyre::Tyre()
        {
            // vehicle specific constants
            FunctionCurve3 slipAngleAtLateralForceAndLoad; // slipAngleAtLateralForceAndLoad is the slip angle[rad] at lateral force[N] and load[N]
        }

        Tyre::Tyre(FunctionCurve3 slipAngleAtLateralForceAndLoad)
        {
            // vehicle specific constants
            this->slipAngleAtLateralForceAndLoad = slipAngleAtLateralForceAndLoad; // slipAngleAtLateralForceAndLoad is the slip angle[rad] at lateral force[N] and load[N]
        }

        double Tyre::getLateralForce(double slipAngle, double load)
        {
            return slipAngleAtLateralForceAndLoad.getYValue(slipAngle, load);
        }
    }
}