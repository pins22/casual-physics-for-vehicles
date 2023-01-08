#include "vehicle/steering/Cornering.h"
#include "vehicle/tyre/Tyre.h"
#include <cmath>

namespace cpv
{
    namespace vehicle
    {
        // vehicle specific constants
        Tyre frontTyre;   // tyre is the front tyre class of the vehicle
        Tyre rearTyre;    // tyre is the rear tyre class of the vehicle
        double wheelBase; // wheelBase is the distance between the front and rear axle of the vehicle[m]
        double inertia;   // inertia is the inertia of the vehicle[kg*m^2]

        Cornering::Cornering()
        {
            frontTyre = Tyre();
            rearTyre = Tyre();
            wheelBase = 0.0;
            inertia = 0.0;
        }

        Cornering::Cornering(Tyre frontTyre, Tyre rearTyre, double wheelBase, double inertia)
        {
            this->frontTyre = frontTyre;
            this->rearTyre = rearTyre;
            this->wheelBase = wheelBase;
            this->inertia = inertia;
        }

        // calculate the car turning torque [Nm]
        double Cornering::getCarTurningTorque(double steeringAngle, double frontWheelLateralForce, double rearWheelLateralForce, double percentageOfWeightOnFrontWheel)
        {
            return cos(steeringAngle) * frontWheelLateralForce * (1 - percentageOfWeightOnFrontWheel) * wheelBase - rearWheelLateralForce * percentageOfWeightOnFrontWheel * wheelBase;
        }

        // calculate the angular acceleration of the vehicle [rad/s^2]
        double Cornering::getAngularAcceleration(double steeringAngle, double frontWheelLateralForce, double rearWheelLateralForce, double percentageOfWeightOnFrontWheel)
        {
            return getCarTurningTorque(steeringAngle, frontWheelLateralForce, rearWheelLateralForce, percentageOfWeightOnFrontWheel) / inertia;
        }

        // calculate the angular acceleration of the vehicle [rad/s^2]
        double Cornering::getAngularAcceleration(double carTurningTorque)
        {
            return carTurningTorque / inertia;
        }

        // calculate the angular velocity of the vehicle [rad/s]
        double Cornering::getAngularVelocity(double longitudinalVelocity, double steeringAngle)
        {
            return longitudinalVelocity / getTurningRadius(steeringAngle);
        }

        double Cornering::getTurningRadius(double steeringAngle)
        {
            return wheelBase / tan(steeringAngle);
        }

        // calculate the front tyre slip angle [rad]
        double Cornering::getFrontTyreSlipAngle(double longitudinalVelocity, double lateralVelocity, double angularVelocity, double percentageOfWeightOnFrontWheel, double steeringAngle)
        {
            return atan((lateralVelocity + angularVelocity * (1 - percentageOfWeightOnFrontWheel) * wheelBase) / longitudinalVelocity) - steeringAngle * sgn(longitudinalVelocity);
        }

        // calculate the rear tyre slip angle [rad]
        double Cornering::getRearTyreSlipAngle(double longitudinalVelocity, double lateralVelocity, double angularVelocity, double percentageOfWeightOnFrontWheel)
        {
            return atan((lateralVelocity - angularVelocity * percentageOfWeightOnFrontWheel * wheelBase) / longitudinalVelocity);
        }

        // calculate the front lateral force [N]
        double Cornering::getFrontLateralForce(double slipAngle, double load)
        {
            return frontTyre.getLateralForce(slipAngle, load);
        }

        // calculate the rear lateral force [N]
        double Cornering::getRearLateralForce(double slipAngle, double load)
        {
            return rearTyre.getLateralForce(slipAngle, load);
        }

        template <typename T>
        int sgn(T val)
        {
            return (T(0) < val) - (val < T(0));
        }
    }
}
