#include "vehicle/movement/LateralForceModel.h"
#include <cmath>

namespace cpv
{
    namespace vehicle
    {
        // constants
        double mass;                      // mass is the total mass of the vehicle [kg]
        double gravitationalAcceleration; // gravitationalAcceleration is the gravitational acceleration of the vehicle [m/s^2]

        // Default constructor for the CpvLateralForceModel class
        LateralForceModel::LateralForceModel()
        {
            mass = 0;
            gravitationalAcceleration = 0;
        }

        // Basic constructor for the CpvLateralForceModel class
        LateralForceModel::LateralForceModel(double mass, double gravitationalAcceleration)
        {
            this->mass = mass;
            this->gravitationalAcceleration = gravitationalAcceleration;
        }

        // Get front wheel lateral force[N]
        double LateralForceModel::getFrontWheelLateralForce(double frontLateralForce, double slope)
        {
            return frontLateralForce + calculateGravitationalForce(slope);
        }

        // Get rear wheel lateral force[N]
        double LateralForceModel::getRearWheelLateralForce(double rearLateralForce, double slope)
        {
            return rearLateralForce + calculateGravitationalForce(slope);
        }

        // Calculate the gravitational force[N] at the given slope
        double LateralForceModel::calculateGravitationalForce(double slope)
        {
            return mass * gravitationalAcceleration * sin(slope);
        }
    }
}