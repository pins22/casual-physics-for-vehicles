#include "vehicle/movement/WeightTransfer.h"
#include <cmath>

namespace cpv
{
    namespace vehicle
    {
        WeightTransfer::WeightTransfer()
        {
            this->vehicleMass = 0;
            this->gravity = 0;
            this->weightDistributionFront = 0;
            this->centreOfGravityHeight = 0;
            this->wheelBase = 0;
            this->trackWidth = 0;
            this->maxBodyRollAngle = 0;
        }

        WeightTransfer::WeightTransfer(double vehicleMass, double gravity, double weightDistributionFront, double centreOfGravityHeight, double wheelBase, double trackWidth, double maxBodyRollAngle)
        {
            this->vehicleMass = vehicleMass;
            this->gravity = gravity;
            this->weightDistributionFront = weightDistributionFront;
            this->centreOfGravityHeight = centreOfGravityHeight;
            this->wheelBase = wheelBase;
            this->trackWidth = trackWidth;
            this->maxBodyRollAngle = maxBodyRollAngle;
        }

        double WeightTransfer::getFrontAxleWeightWhenStationary()
        {
            return (weight * weightDistributionFront);
        }

        double WeightTransfer::getRearAxleWeightWhenStationary()
        {
            return (weight * (1 - weightDistributionFront));
        }

        double WeightTransfer::getLongitudinalWeightTransferFromAcceleration(double longitudinalAcceleration)
        {
            return (vehicleMass * longitudinalAcceleration * (centreOfGravityHeight / wheelBase));
        }

        double WeightTransfer::getLateralWeightTransferFromAcceleration(double lateralAcceleration, double weightOnFrontAxle, double weightOnRearAxle)
        {
            return getFrontLateralWeightTransferFromAcceleration(lateralAcceleration, weightOnFrontAxle) + getRearLateralWeightTransferFromAcceleration(lateralAcceleration, weightOnRearAxle);
        }

        double WeightTransfer::getBodyRollAngleFromLateralWeightTransfer(double lateralAcceleration, double lateralWeightTransfer)
        {
            return sgn(lateralAcceleration) * (lateralWeightTransfer / weight) * maxBodyRollAngle;
        }

        double WeightTransfer::getLateralWeightTransferFromBodyRoll(double lateralAcceleration, double bodyRollAngle)
        {
            return (sgn(lateralAcceleration) * centreOfGravityHeight * sin(abs(bodyRollAngle)) / trackWidth) * weight;
        }

        double WeightTransfer::getFrontLateralWeightTransferFromAcceleration(double lateralAcceleration, double weightOnFrontAxle)
        {
            return (lateralAcceleration / gravity) * weightOnFrontAxle * centreOfGravityHeight / trackWidth;
        }

        double WeightTransfer::getRearLateralWeightTransferFromAcceleration(double lateralAcceleration, double weightOnRearAxle)
        {
            return (lateralAcceleration / gravity) * weightOnRearAxle * centreOfGravityHeight / trackWidth;
        }

        template <typename T>
        int sgn(T val)
        {
            return (T(0) < val) - (val < T(0));
        }

        // getters and setters
        double WeightTransfer::getVehicleMass() { return vehicleMass; }
        void WeightTransfer::setVehicleMass(double vehicleMass) { this->vehicleMass = vehicleMass; }
        double WeightTransfer::getGravity() { return gravity; }
        void WeightTransfer::setGravity(double gravity) { this->gravity = gravity; }
        double WeightTransfer::getWeightDistributionFront() { return weightDistributionFront; }
        void WeightTransfer::setWeightDistributionFront(double weightDistributionFront) { this->weightDistributionFront = weightDistributionFront; }
        double WeightTransfer::getCentreOfGravityHeight() { return centreOfGravityHeight; }
        void WeightTransfer::setCentreOfGravityHeight(double centreOfGravityHeight) { this->centreOfGravityHeight = centreOfGravityHeight; }
        double WeightTransfer::getWheelBase() { return wheelBase; }
        void WeightTransfer::setWheelBase(double wheelBase) { this->wheelBase = wheelBase; }
        double WeightTransfer::getTrackWidth() { return trackWidth; }
        void WeightTransfer::setTrackWidth(double trackWidth) { this->trackWidth = trackWidth; }
        double WeightTransfer::getMaxBodyRollAngle() { return maxBodyRollAngle; }
        void WeightTransfer::setMaxBodyRollAngle(double maxBodyRollAngle) { this->maxBodyRollAngle = maxBodyRollAngle; }
    }
}