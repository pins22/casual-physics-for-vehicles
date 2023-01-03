#pragma once

namespace cpv
{
    namespace vehicle
    {
        class LateralForceModel
        {
        public:
            /**
             * @brief Default constructor for the LateralForceModel class
             * @details Sets all values to 0
             */
            LateralForceModel();

            /**
             * @brief Basic constructor for the LateralForceModel class
             * @details Sets all values to the given values
             *
             * @param mass the mass of the vehicle[kg]
             * @param gravitationalAcceleration the gravitational acceleration [m/s^2]
             */
            LateralForceModel(double mass, double gravitationalAcceleration);

            /**
             * @brief Get front wheel lateral force[N]
             * @details The front wheel lateral force is calculated using the steering force and the slope
             *
             * @param frontCorneringForce Get from Cornering class
             * @param percentageOfWeightOnFrontWheel
             * @param slope
             * @return double
             */
            double getFrontWheelLateralForce(double frontCorneringForce, double percentageOfWeightOnFrontWheel, double slope);

            /**
             * @brief Get rear wheel lateral force[N]
             * @details The rear wheel lateral force is calculated using the slope
             *
             * @param rearCorneringForce Get from Cornering class
             * @param percentageOfWeightOnFrontWheel
             * @param slope
             * @return double
             */
            double getRearWheelLateralForce(double rearCorneringForce, double percentageOfWeightOnFrontWheel, double slope);

        private:
            // constants
            double mass;                      // mass is the mass of the vehicle [kg]
            double gravitationalAcceleration; // gravitationalAcceleration is the gravitational acceleration [m/s^2]

            /**
             * @brief Calculate the front gravitational force[N] at the given slope
             * @details The gravitational force is calculated using the mass and the slope
             *
             * @param slope
             * @param percentageOfWeightOnFrontWheel
             * @return double
             */
            double calculateFrontGravitationalForce(double slope, double percentageOfWeightOnFrontWheel);

            /**
             * @brief Calculate the rear gravitational force[N] at the given slope
             * @details The gravitational force is calculated using the mass and the slope
             *
             * @param slope
             * @param percentageOfWeightOnFrontWheel
             * @return double
             */
            double calculateRearGravitationalForce(double slope, double percentageOfWeightOnFrontWheel);
        };
    }
}