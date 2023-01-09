#pragma once

#include "vehicle/tyre/Tyre.h"

namespace cpv
{
    namespace vehicle
    {
        class Cornering
        {
        public:
            /**
             * @brief Default constructor for the Cornering class
             * @details Sets all values to 0
             */
            Cornering();

            /**
             * @brief Basic constructor for the Cornering class
             * @details Sets all values to the given values
             *
             * @param frontTyre the front tyre class of the vehicle
             * @param rearTyre the rear tyre class of the vehicle
             * @param wheelBase the distance between the front and rear axle of the vehicle[m]
             * @param inertia the moment of inertia of the vehicle [kg*m^2]
             */
            Cornering(Tyre frontTyre, Tyre rearTyre, double wheelBase, double inertia);

            /**
             * @brief Calculate the car turning torque[Nm]
             * @details The car turning torque is calculated using the front and rear wheel lateral force
             *
             * @param steeringAngle User input
             * @param frontWheelLateralForce Get from LateralForceModel class
             * @param rearWheelLateralForce Get from LateralForceModel class
             * @param percentageOfWeightOnFrontWheel the percentage of weight on the front wheel
             * @return double
             */
            double getCarTurningTorque(double steeringAngle, double frontWheelLateralForce, double rearWheelLateralForce, double percentageOfWeightOnFrontWheel);

            /**
             * @brief Calculate the angular acceleration of the vehicle [rad/s^2]
             * @details The angular acceleration is calculated using the car turning torque and the moment of inertia of the vehicle
             *
             * @param steeringAngle User input
             * @param frontWheelLateralForce Get from LateralForceModel class
             * @param rearWheelLateralForce Get from LateralForceModel class
             * @param percentageOfWeightOnFrontWheel the percentage of weight on the front wheel
             */
            double getAngularAcceleration(double steeringAngle, double frontWheelLateralForce, double rearWheelLateralForce, double percentageOfWeightOnFrontWheel);

            /**
             * @brief Calculate the angular acceleration of the vehicle [rad/s^2]
             * @details The angular acceleration is calculated using the car turning torque and the moment of inertia of the vehicle
             *
             * @param carTurningTorque Get from getCarTurningTorque function
             */
            double getAngularAcceleration(double carTurningTorque);

            /**
             * @brief Get the angular velocity of the vehicle
             *
             * @param longitudinalVelocity the longitudinal velocity[m/s] of the vehicle
             * @param steeringAngle the steering angle[rad] of the vehicle (user input)
             * @return double
             */
            double getAngularVelocity(double longitudinalVelocity, double steeringAngle);

            /**
             * @brief Get the turning radius of the vehicle
             *
             * @param steeringAngle the steering angle[rad] of the vehicle (user input)
             * @return double
             */
            double getTurningRadius(double steeringAngle);

            /**
             * @brief Get the front tyre slip angle[rad]
             *
             * @param longitudinalVelocity the longitudinal velocity[m/s] of the vehicle
             * @param lateralVelocity the lateral velocity[m/s] of the vehicle
             * @param angularVelocity the angular velocity[rad/s] of the vehicle
             * @param percentageOfWeightOnFrontWheel the percentage of weight on the front wheel
             * @param steeringAngle the steering angle[rad] of the vehicle (user input)
             * @return double
             */
            double getFrontTyreSlipAngle(double longitudinalVelocity, double lateralVelocity, double angularVelocity, double percentageOfWeightOnFrontWheel, double steeringAngle);

            /**
             * @brief Get the rear tyre slip angle[rad]
             *
             * @param longitudinalVelocity the longitudinal velocity[m/s] of the vehicle
             * @param lateralVelocity the lateral velocity[m/s] of the vehicle
             * @param angularVelocity the angular velocity[rad/s] of the vehicle
             * @param percentageOfWeightOnFrontWheel the percentage of weight on the front wheel
             * @return double
             */
            double getRearTyreSlipAngle(double longitudinalVelocity, double lateralVelocity, double angularVelocity, double percentageOfWeightOnFrontWheel);

            /**
             * @brief Get the front lateral force[N]
             *
             * @param slipAngle the slip angle[rad] of the front tyre
             * @param load the load[N] of the front tyre
             * @return double
             */
            double getFrontLateralForce(double slipAngle, double load);

            /**
             * @brief Get the rear lateral force[N]
             *
             * @param slipAngle the slip angle[rad] of the rear tyre
             * @param load the load[N] of the rear tyre
             * @return double
             */
            double getRearLateralForce(double slipAngle, double load);

        private:
            // vehicle specific constants
            Tyre frontTyre;   // tyre is the front tyre class of the vehicle
            Tyre rearTyre;    // tyre is the rear tyre class of the vehicle
            double wheelBase; // wheelBase is the distance between the front and rear axle of the vehicle[m]
            double inertia;   // inertia is the rotational inertia of the vehicle[kg*m^2]

            /**
             * @brief Get the sign of a value
             *
             * @tparam T
             * @param val
             * @return int
             */
            template <typename T>
            int sgn(T val);
        };
    }
}