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
        double LateralForceModel::getFrontWheelLateralForce(double frontCorneringForce, double percentageOfWeightOnFrontWheel, double slope)
        {
            double frontGravitationalForce = calculateFrontGravitationalForce(slope, percentageOfWeightOnFrontWheel);
            return frontCorneringForce + frontGravitationalForce;
        }

        // Get rear wheel lateral force[N]
        double LateralForceModel::getRearWheelLateralForce(double rearCorneringForce, double percentageOfWeightOnFrontWheel, double slope)
        {
            double rearGravitationalForce = calculateRearGravitationalForce(slope, percentageOfWeightOnFrontWheel);
            return rearCorneringForce + rearGravitationalForce;
        }

        // Calculate the front gravitational force[N] at the given slope
        double LateralForceModel::calculateFrontGravitationalForce(double slope, double percentageOfWeightOnFrontWheel)
        {
            double frontWeight = mass * percentageOfWeightOnFrontWheel;
            return frontWeight * gravitationalAcceleration * sin(slope);
        }

        // Calculate the rear gravitational force[N] at the given slope
        double LateralForceModel::calculateRearGravitationalForce(double slope, double percentageOfWeightOnFrontWheel)
        {
            double rearWeight = mass * (1 - percentageOfWeightOnFrontWheel);
            return rearWeight * gravitationalAcceleration * sin(slope);
        }
    }
}
