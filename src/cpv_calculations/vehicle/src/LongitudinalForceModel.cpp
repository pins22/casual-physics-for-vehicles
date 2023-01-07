#include "vehicle/movement/LongitudinalForceModel.h"
#include <cmath>

namespace cpv
{
    namespace vehicle
    {
        // constants
        double mass;                      // mass is the total mass of the vehicle [kg]
        double gravitationalAcceleration; // gravitationalAcceleration is the gravitational acceleration of the vehicle [m/s^2]
        double dragConst;                 // dragConst is the drag coefficient of the vehicle
        double rollingResistanceConst;    // rollingResistanceConst is the rolling resistance coefficient of the vehicle (tires)

        // Default constructor for the CpvLongitudinalForceModel class
        // Sets all values to 0
        LongitudinalForceModel::LongitudinalForceModel()
        {
            mass = 0.0;
            gravitationalAcceleration = 0.0;
            dragConst = 0.0;
            rollingResistanceConst = 0.0;
        }

        // Basic constructor for the CpvLongitudinalForceModel class
        // Sets all values to the given values
        LongitudinalForceModel::LongitudinalForceModel(double mass, double gravitationalAcceleration, double dragConst, double rollingResistanceConst)
        {
            this->mass = mass;
            this->gravitationalAcceleration = gravitationalAcceleration;
            this->dragConst = dragConst;
            this->rollingResistanceConst = rollingResistanceConst;
        }

        // Calculate the longitudinal force[N] at the given velocity, wheelTorque on the wheels, radius of the wheels, the slope of the road, the amount of braking [0, 1]
        double LongitudinalForceModel::calculateLongitudinalForce(double velocity, double wheelTorque, double radius, double slope, double brakingTorque)
        {
            return calculateDragForce(velocity) + calculateRollingResistanceForce(velocity) + calculateGravitationalForce(slope) + calculateTractionForce(wheelTorque, radius) + calculateBrakingForce(brakingTorque, radius);
        }

        // Calculate the drag force[N] at the given velocity
        // The drag force is calculated using the drag constant and the velocity
        double LongitudinalForceModel::calculateDragForce(double velocity)
        {
            return -dragConst * velocity * abs(velocity);
        }

        // Calculate the rolling resistance force[N] at the given velocity
        // The rolling resistance force is calculated using the rolling resistance constant and the velocity
        double LongitudinalForceModel::calculateRollingResistanceForce(double velocity)
        {
            return -rollingResistanceConst * velocity;
        }

        // Calculate the effect of the gravitational force on the vehicles longitudinal force
        // The gravitational force is calculated using the mass of the vehicle, gravitational acceleration, the slope of the road
        double LongitudinalForceModel::calculateGravitationalForce(double slope)
        {
            return mass * gravitationalAcceleration * sin(slope);
        }

        // Get the traction force[N] at the given wheelTorque on the wheels and the radius of the wheels
        // The traction force is calculated using the wheelTorque on the wheels and the radius of the wheels
        double LongitudinalForceModel::calculateTractionForce(double wheelTorque, double radius)
        {
            return wheelTorque / radius;
        }

        // Get the braking force[N] at the given amount of braking
        // The braking force is calculated using the amount of braking and the braking force of the brake class
        double LongitudinalForceModel::calculateBrakingForce(double brakingTorque, double radius)
        {
            return brakingTorque / radius;
        }
    }
}
