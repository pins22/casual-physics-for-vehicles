#include "vehicle/brake/Brake.h"

namespace cpv
{
    namespace vehicle
    {
        namespace brake
        {
            // Default constructor for the Brake class
            // Sets all values to 0
            Brake::Brake()
            {
                brakeConst = 0.0;
            }

            // Basic constructor for the Brake class
            // Sets all values to the given values
            Brake::Brake(double brakeConst)
            {
                this->brakeConst = brakeConst;
            }

            // Get the brake force[N]
            // The brake force is calculated using the brake force constant and unit vector of the movement direction
            double Brake::calculateBrakingForce(double brake)
            {
                return brakeConst * brake;
            }
        }
    }
}