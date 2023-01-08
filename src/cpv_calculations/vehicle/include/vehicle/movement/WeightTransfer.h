#pragma once

namespace cpv
{
    namespace vehicle
    {
        class WeightTransfer
        {
        public:
            /**
             * @brief default constructor for the WeightTransfer class
             * @details The constructor sets the default constants for the vehicle
             */
            WeightTransfer();

            /**
             * @brief Basic constructor for the WeightTransfer class
             * @details The constructor sets the user defined constants for the vehicle
             *
             * @param vehicleMass the weight of the vehicle [N]
             * @param gravity the gravitational acceleration [m/s^2]
             * @param weightDistributionFront the weight percentage of the front axle of the vehicle when stationary
             * @param centreOfGravityHeight the height of the centre of gravity of the vehicle [m]
             * @param wheelBase the length between the front and rear axle of the vehicle [m]
             * @param trackWidth the width between the left and right axle of the vehicle [m]
             * @param maxBodyRollAngle the maximum body roll angle of the vehicle [rad]
             */
            WeightTransfer(double vehicleMass, double gravity, double weightDistributionFront, double centreOfGravityHeight, double wheelBase, double trackWidth, double maxBodyRollAngle);

            /**
             * @brief Get the weight on the front axle when the vehicle is stationary
             */
            double getFrontAxleWeightWhenStationary();

            /**
             * @brief Get the weight on the rear axle when the vehicle is stationary
             */
            double getRearAxleWeightWhenStationary();

            /**
             * @brief Get the longitudinal weight transfer of the vehicle from acceleration (+ for front, - for rear)
             * @details The weight transfer is calculated using the longitudinal acceleration of the vehicle
             *
             * @param longitudinalAcceleration the longitudinal acceleration of the vehicle [m/s^2]
             */
            double getLongitudinalWeightTransferFromAcceleration(double longitudinalAcceleration);

            /**
             * @brief Get the lateral weight transfer of the vehicle from acceleration (+ for left, - for right)
             * @details The weight transfer is calculated using the lateral acceleration of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param weightOnFrontAxle the weight on the front axle of the vehicle [N]
             * @param weightOnRearAxle the weight on the rear axle of the vehicle [N]
             */
            double getLateralWeightTransferFromAcceleration(double lateralAcceleration, double weightOnFrontAxle, double weightOnRearAxle);

            /**
             * @brief Get the body roll angle of the vehicle from lateral weight transfer (+ for left, - for right)
             * @details The body roll angle is calculated using the lateral weight transfer of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param lateralWeightTransfer the lateral weight transfer of the vehicle [N] (change in weight on the left or right axle)
             */
            double getBodyRollAngleFromLateralWeightTransfer(double lateralAcceleration, double lateralWeightTransfer);

            /**
             * @brief Get the weight transfer due to body roll (+ for left, - for right)
             * @details The weight transfer is calculated using the body roll angle of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param bodyRollAngle the body roll angle of the vehicle [rad]
             */
            double getLateralWeightTransferFromBodyRoll(double lateralAcceleration, double bodyRollAngle);

            // getters and setters
            double getVehicleMass();
            void setVehicleMass(double vehicleMass);
            double getGravity();
            void setGravity(double gravity);
            double getWeightDistributionFront();
            void setWeightDistributionFront(double weightDistributionFront);
            double getCentreOfGravityHeight();
            void setCentreOfGravityHeight(double centreOfGravityHeight);
            double getWheelBase();
            void setWheelBase(double wheelBase);
            double getTrackWidth();
            void setTrackWidth(double trackWidth);
            double getMaxBodyRollAngle();
            void setMaxBodyRollAngle(double maxBodyRollAngle);

            double weight = vehicleMass * gravity;

        private:
            // user defined constants
            double vehicleMass;             // the weight of the vehicle [kg]
            double gravity;                 // the gravitational acceleration [m/s^2]
            double weightDistributionFront; // the weight percentage of the front axle of the vehicle when stationary
            double centreOfGravityHeight;   // the height of the centre of gravity of the vehicle [m]
            double wheelBase;               // the length between the front and rear axle of the vehicle [m]
            double trackWidth;              // the width between the left and right axle of the vehicle [m]
            double maxBodyRollAngle;        // the maximum body roll angle of the vehicle [rad]

            /**
             * @brief Get the sign of a value
             *
             * @tparam T
             * @param val
             * @return int
             */
            template <typename T>
            int sgn(T val);

            /**
             * @brief Get the front lateral weight transfer of the vehicle from acceleration (+ for left, - for right)
             * @details The weight transfer is calculated using the lateral acceleration of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param weightOnFrontAxle the weight on the front axle of the vehicle [N]
             */
            double getFrontLateralWeightTransferFromAcceleration(double lateralAcceleration, double weightOnFrontAxle);

            /**
             * @brief Get the rear lateral weight transfer of the vehicle from acceleration (+ for left, - for right)
             * @details The weight transfer is calculated using the lateral acceleration of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param weightOnRearAxle the weight on the rear axle of the vehicle [N]
             */
            double getRearLateralWeightTransferFromAcceleration(double lateralAcceleration, double weightOnRearAxle);
        };
    }
}