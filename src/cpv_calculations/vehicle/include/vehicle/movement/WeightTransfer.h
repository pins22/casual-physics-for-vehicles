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
             * @details The weight transfer is calculated using the longitudinal acceleration of the vehicle and is the change in weight on the front or rear axle
             *
             * @param longitudinalAcceleration the longitudinal acceleration of the vehicle [m/s^2]
             */
            double getLongWeightTransferFromAcceleration(double longitudinalAcceleration);

            /**
             * @brief Get the front lateral weight transfer of the vehicle from acceleration (+ for left, - for right)
             * @details The weight transfer is calculated using the lateral acceleration of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param weightOnFrontAxle the weight on the front axle of the vehicle [N]
             */
            double getFrontLatWeightTransferFromAcceleration(double lateralAcceleration, double weightOnFrontAxle);

            /**
             * @brief Get the rear lateral weight transfer of the vehicle from acceleration (+ for left, - for right)
             * @details The weight transfer is calculated using the lateral acceleration of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param weightOnRearAxle the weight on the rear axle of the vehicle [N]
             */
            double getRearLatWeightTransferFromAcceleration(double lateralAcceleration, double weightOnRearAxle);

            /**
             * @brief Get the lateral weight transfer of the vehicle from acceleration (+ for left, - for right)
             * @details The weight transfer is calculated using the lateral acceleration of the vehicle
             *
             * @param frontLatWeightTransferAccel the front change in weight due to lateral acceleration of the vehicle [m/s^2] (return of getLongWeightTransferFromAcceleration())
             * @param rearLatWeightTransferAccel the rear change in weight due to lateral acceleration of the vehicle [m/s^2] (return of getLongWeightTransferFromAcceleration())
             *
             * @return double
             */
            double getLatWeightTransferFromAcceleration(double frontLatWeightTransferAccel, double rearLatWeightTransferAccel);

            /**
             * @brief Get the body roll angle of the vehicle from lateral weight transfer (+ for left, - for right)
             * @details The body roll angle is calculated using the lateral weight transfer of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param lateralWeightTransfer the lateral weight transfer of the vehicle [N] (change in weight on the left or right axle)
             */
            double getBodyRollAngleFromLatWeightTransfer(double lateralAcceleration, double lateralWeightTransfer);

            /**
             * @brief Get the weight transfer due to body roll (+ for left, - for right)
             * @details The weight transfer is calculated using the body roll angle of the vehicle
             *
             * @param lateralAcceleration the lateral acceleration of the vehicle [m/s^2]
             * @param bodyRollAngle the body roll angle of the vehicle [rad]
             */
            double getLatWeightTransferFromBodyRoll(double lateralAcceleration, double bodyRollAngle);

            /**
             * @brief Get amount of change in weight on the front right wheel.
             * @details The change in weight is calculated using the lateral weight transfer of the vehicle and the longitudinal weight transfer of the vehicle
             *
             * @param frontLatWeightTransfer the lateral weight transfer of the vehicle [N] (change in weight on the left or right axle) (return of function getFrontLatWeightTransferFromAcceleration())
             * @param longWeightTransferAccel the longitudinal weight transfer of the vehicle [N] due to acceleration
             * @param weightTransferRoll the weight transfer of the vehicle [N] due to body roll (get from func getLatWeightTransferFromBodyRoll())
             * 
             * @return double
             */
            double getFrontRightWheelWeightChange(double frontLatWeightTransfer, double longWeightTransferAccel, double weightTransferRoll);

            /**
             * @brief Get amount of change in weight on the front left wheel.
             * @details The change in weight is calculated using the lateral weight transfer of the vehicle and the longitudinal weight transfer of the vehicle
             *
             * @param frontLatWeightTransfer the lateral weight transfer of the vehicle [N] (change in weight on the left or right axle) (return of function getFrontLatWeightTransferFromAcceleration())
             * @param longWeightTransferAccel the longitudinal weight transfer of the vehicle [N] due to acceleration
             * @param weightTransferRoll the weight transfer of the vehicle [N] due to body roll (get from func getLatWeightTransferFromBodyRoll())
             * 
             * @return double
             */
            double getFrontLeftWheelWeightChange(double frontLatWeightTransfer, double longWeightTransferAccel, double weightTransferRoll);

            /**
             * @brief Get amount of change in weight on the rear right wheel.
             * @details The change in weight is calculated using the lateral weight transfer of the vehicle and the longitudinal weight transfer of the vehicle
             *
             * @param rearLatWeightTransfer the lateral weight transfer of the vehicle [N] (change in weight on the left or right axle) (return of function getRearLatWeightTransferFromAcceleration())
             * @param longWeightTransferAccel the longitudinal weight transfer of the vehicle [N] due to acceleration
             * @param weightTransferRoll the weight transfer of the vehicle [N] due to body roll (get from func getLatWeightTransferFromBodyRoll())
             * 
             * @return double
             */
            double getRearRightWheelWeightChange(double rearLatWeightTransfer, double longWeightTransferAccel, double weightTransferRoll);

            /**
             * @brief Get amount of change in weight on the rear left wheel.
             * @details The change in weight is calculated using the lateral weight transfer of the vehicle and the longitudinal weight transfer of the vehicle
             *
             * @param rearLatWeightTransfer the lateral weight transfer of the vehicle [N] (change in weight on the left or right axle) (return of function getRearLatWeightTransferFromAcceleration())
             * @param longWeightTransferAccel the longitudinal weight transfer of the vehicle [N] due to acceleration
             * @param weightTransferRoll the weight transfer of the vehicle [N] due to body roll (get from func getLatWeightTransferFromBodyRoll())
             * 
             * @return double
             */
            double getRearLeftWheelWeightChange(double rearLatWeightTransfer, double longWeightTransferAccel, double weightTransferRoll);

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
        };
    }
}