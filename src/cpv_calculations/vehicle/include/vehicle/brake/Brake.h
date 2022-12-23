#ifndef CPV_BRAKE_H
#define CPV_BRAKE_H

namespace cpv
{
    namespace vehicle
    {
        /**
         * @brief Simple brake model
         * @details This class is used to calculate the brake force of a vehicle
         */
        class Brake
        {
        public:
            /**
             * @brief Default constructor for the Brake class
             * @details Sets all values to 0
             */
            Brake();

            /**
             * @brief Basic constructor for the Brake class
             * @details Sets all values to the given values
             *
             * @param brakeConst the brake constant of the vehicle
             */
            Brake(double brakeConst);

            /**
             * @brief Get the brake force[N]
             * @details The brake force is calculated using the brake force constant and the unit vector of the movement direction
             *
             * @param movingDirection unit vector of the movement direction
             * @param brake the brake amount [0, 1]
             */
            double calculateBrakingForce(double brake);

        private:
            // vehicle specific constants
            double brakeConst; // brakeConst is the brake constant of the vehicle
        };
    }
}

#endif