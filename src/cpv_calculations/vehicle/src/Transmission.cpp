#include "vehicle/powertrain/Transmission.h"
#include <vector>
#include <cmath>

namespace cpv
{
    namespace vehicle
    {
        std::vector<double> gearRatios; // gear ratios of the transmission (0 = reverse, 1 = 1st, 2 = 2nd, 3 = 3rd, 4 = 4th, 5 = 5th, 6 = 6th...)
        double finalDriveRatio;         // final drive (ratio of the differential)
        int currentGear;                // current gear (-1 = reverse, 0 = neutral, 1 = 1st, 2 = 2nd, 3 = 3rd, 4 = 4th, 5 = 5th, 6 = 6th...)

        Transmission::Transmission()
        {
            gearRatios = std::vector<double>(1.0, 1.0);
            finalDriveRatio = 1.0;
            currentGear = 0;
        }

        Transmission::Transmission(std::vector<double> gearRatios, double finalDriveRatio)
        {
            this->gearRatios = gearRatios;
            this->finalDriveRatio = finalDriveRatio;
            currentGear = 0;
        }

        Transmission &Transmission::operator=(const Transmission &other)
        {
            gearRatios = other.gearRatios;
            finalDriveRatio = other.finalDriveRatio;
            currentGear = other.currentGear;
            return *this;
        }

        double Transmission::calculateWheelTorque(double engineTorque, int gear)
        {
            return engineTorque * gearRatios[gear] * finalDriveRatio;
        }

        double Transmission::calculateVehicleVelocity(double engineRpm, int gear, double wheelRadius)
        {
            // wheel radius * wheel angular velocity (rad/s)
            return wheelRadius * 2 * M_PI * engineRpm / (60 * gearRatios[gear] * finalDriveRatio);
        }

        double Transmission::calculateEngineRpm(double vehicleVelocity, int gear, double wheelRadius)
        {
            return vehicleVelocity * 60 * gearRatios[gear] * finalDriveRatio / (2 * M_PI * wheelRadius);
        }

        std::vector<double> Transmission::getGearRatios()
        {
            return gearRatios;
        }

        double Transmission::getFinalDriveRatio()
        {
            return finalDriveRatio;
        }

        int Transmission::getCurrentGear()
        {
            return currentGear;
        }

        void Transmission::setCurrentGear(int gear)
        {
            currentGear = gear;
        }
        
        void Transmission::setFinalDriveRatio(double finalDriveRatio)
        {
            this->finalDriveRatio = finalDriveRatio;
        }
    }
}