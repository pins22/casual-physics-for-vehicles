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
             */
            Cornering(Tyre frontTyre, Tyre rearTyre, double wheelBase);

            /**
             * @brief Get the angular velocity of the vehicle
             *
             * @param longitudinalVelocity the longitudinal velocity[m/s] of the vehicle
             * @param steeringAngle the steering angle[rad] of the vehicle (user input)
             * @return double
             */
            double getAngularVelocity(double longitudinalVelocity, double steeringAngle);

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