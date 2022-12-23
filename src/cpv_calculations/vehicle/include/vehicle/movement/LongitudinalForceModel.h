#include "vehicle/brake/Brake.h"

#ifndef CPV_LONGITUDINAL_FORCE_MODEL_H
#define CPV_LONGITUDINAL_FORCE_MODEL_H

namespace cpv
{
    namespace vehicle
    {
        class LongitudinalForceModel
        {
        public:
            /**
             * @brief Default constructor for the CpvLongitudinalForceModel class
             * @details Sets all values to 0
             */
            LongitudinalForceModel();

            /**
             * @brief Basic constructor for the CpvLongitudinalForceModel class
             * @details Sets all values to the given values
             *
             * @param mass the mass of the vehicle [kg]
             * @param dragConst the drag constant of the vehicle
             * @param rollingResistanceConst the rolling resistance constant of the vehicle
             * @param brake the brake class of the vehicle
             */
            LongitudinalForceModel(double mass, double dragConst, double rollingResistanceConst, Brake brakeType);

            /**
             * @brief Get the longitudinal force[N] at the given velocity, wheelTorque on the wheels, radius of the wheels, the slope of the road
             * @details The longitudinal force is calculated using the drag force, the rolling resistance force, the gravitational force and the traction force
             *
             * @param velocity the velocity of the vehicle [m/s]
             * @param wheelTorque the wheelTorque on the wheels [Nm]
             * @param radius the radius of the wheels [m]
             * @param slope the slope of the road [rad] (flat = 0, uphill = positive, downhill = negative)
             * @param brakingAmount the amount of braking [0, 1]
             */
            double calculateLongitudinalForce(double velocity, double wheelTorque, double radius, double slope, double brakingAmount);

        private:
            // vehicle specific constants
            double mass;                   // mass is the mass of the vehicle [kg]
            double dragConst;              // dragConst is the drag constant of the vehicle [kg/m]
            double rollingResistanceConst; // rollingResistanceConst is the rolling resistance constant of the vehicle
            Brake brake;                   // brake is the brake class of the vehicle

            /**
             * @brief Calculate the drag force[N] at the given velocity
             * @details The drag force is calculated using the drag constant and the velocity
             *
             * @param velocity the velocity of the vehicle [m/s]
             */
            double calculateDragForce(double velocity);

            /**
             * @brief Get the rolling resistance force[N] at the given velocity
             * @details The rolling resistance force is calculated using the rolling resistance constant and the velocity
             *
             * @param velocity the velocity of the vehicle [m/s]
             */
            double calculateRollingResistanceForce(double velocity);

            /**
             * @brief Get the effect of the gravitational force on the vehicles longitudinal force
             * @details The gravitational force is calculated using the mass of the vehicle, gravitational acceleration, the slope of the road
             *
             * @param slope the slope of the road [rad] (flat = 0, uphill = positive, downhill = negative)
             */
            double calculateGravitationalForce(double slope);

            /**
             * @brief Get the traction force[N] at the given wheelTorque on the wheels and the radius of the wheels
             * @details The traction force is calculated using the torque on the wheels and the radius of the wheels
             *
             * @param wheelTorque the torque on the wheels [Nm]
             * @param radius the radius of the wheels [m]
             */
            double calculateTractionForce(double wheelTorque, double radius);

            /**
             * @brief Get the braking force[N] at the given Brake class and the braking amount
             * @details The braking force is calculated using the brake force constant and the braking amount
             */
            double calculateBrakingForce(double brakingAmount);
        };
    }
}

#endif