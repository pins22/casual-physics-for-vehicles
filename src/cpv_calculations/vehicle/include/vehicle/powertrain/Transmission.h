#include <vector>

#ifndef CPV_TRANSMISSION_H
#define CPV_TRANSMISSION_H

namespace cpv
{
    namespace vehicle
    {
        class Transmission
        {
        public:
            /**
             * @brief Default constructor for the CpvTransmission class
             * @details Sets all values to 0
             */
            Transmission();

            /**
             * @brief Basic constructor for the CpvTransmission class
             * @details Sets all values to the given values
             *
             * @param gearRatios the gear ratios of the transmission
             * @param finalDriveRatio the final drive ratio of the transmission
             */
            Transmission(std::vector<double> gearRatios, double finalDriveRatio);

            /**
             * @brief Assignment operator for the CpvTransmission class
             *
             * @param other the CpvTransmission to copy
             * @return a reference to the CpvTransmission
             */
            Transmission &operator=(const Transmission &other);

            /**
             * @brief Calculate the wheel torque[N*m] at the current gear
             *
             * @param engineTorque the engine torque[N*m]
             * @param gear the current gear
             * @return double
             */
            double calculateWheelTorque(double engineTorque, int gear);

            /**
             * @brief Calculate the car velocity[m/s] at the current gear
             *
             * @param engineRpm the engine rpm
             * @param gear the current gear
             * @param wheelRadius the wheel radius[m]
             * @return double
             */
            double calculateVehicleVelocity(double engineRpm, int gear, double wheelRadius);

            /**
             * @brief Calculate engine rpm
             * 
             * @param vehicleVelocity the vehicle velocity[m/s]
             * @param gear the current gear
             * @param wheelRadius the wheel radius[m] 
             * @return std::vector<double> 
             */
            double calculateEngineRpm(double vehicleVelocity, int gear, double wheelRadius);

            // getters
            std::vector<double> getGearRatios();
            double getFinalDriveRatio();
            int getCurrentGear();

            // setters
            void setCurrentGear(int gear);

        protected:
            std::vector<double> gearRatios; // gear ratios of the transmission (0 = reverse, 1 = 1st, 2 = 2nd, 3 = 3rd, 4 = 4th, 5 = 5th, 6 = 6th...)
            double finalDriveRatio;         // final drive (ratio of the differential)
            int currentGear;                // current gear (-1 = reverse, 0 = neutral, 1 = 1st, 2 = 2nd, 3 = 3rd, 4 = 4th, 5 = 5th, 6 = 6th...)
        };
    }
}

#endif