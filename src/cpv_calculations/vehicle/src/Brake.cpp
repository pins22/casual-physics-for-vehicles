#include "vehicle/brake/Brake.h"

namespace cpv
{
    namespace vehicle
    {
        // Default constructor for the Brake class
        // Sets all values to 0
        Brake::Brake()
        {
            maxBrakeTorque = 0.0;
        }

        // Basic constructor for the Brake class
        // Sets all values to the given values
        Brake::Brake(double maxBrakeTorque)
        {
            this->maxBrakeTorque = maxBrakeTorque;
        }

        // Get the brake force[N]
        // The brake force is calculated using the brake force constant and unit vector of the movement direction
        double Brake::calculateBrakingForce(double brakeAmount)
        {
            return maxBrakeTorque * brakeAmount;
        }

        void Brake::setMaxBrakeTorque(double maxBrakeTorque)
        {
            this->maxBrakeTorque = maxBrakeTorque;
        }

        double Brake::getMaxBrakeTorque()
        {
            return maxBrakeTorque;
        }
    }
}
