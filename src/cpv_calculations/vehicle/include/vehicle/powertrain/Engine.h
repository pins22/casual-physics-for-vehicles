#include "core/FunctionCurve3.h"

#ifndef CPV_ENGINE_H
#define CPV_ENGINE_h

namespace cpv
{
    namespace vehicle
    {

        class Engine
        {
        public:
            /**
             * @brief Default constructor for the CpvEngine class
             * @details Sets all values to 0
             */
            Engine();

            /**
             * @brief Basic constructor for the CpvEngine class
             * @details Sets all values to the given values
             *
             * @param torqueCurve the torque curve of the engine
             * @param powerCurve the power curve of the engine
             * @param idleRpm the idle rpm of the engine
             */
            Engine(FunctionCurve3 torqueCurve, int idleRpm);

            /**
             * @brief Assignment operator for the CpvEngine class
             *
             * @param other the CpvEngine to copy
             * @return a reference to the CpvEngine
             */
            Engine &operator=(const Engine &other);

            /**
             * @brief Calculate the torque[N*m] at the current rpm and throttle
             *
             * @return the torque at the current rpm and throttle
             */
            double calculateTorque();

            /**
             * @brief Calculate the power[Watt] at the current rpm and throttle
             *
             * @return the power at the current rpm and throttle
             */
            double calculatePower();

            /**
             * @brief Calculate redline rpm
             *
             * @return the redline rpm
             */

            // getters
            FunctionCurve3 getTorqueCurve();
            int getIdleRpm();
            int getRpm();
            double getThrottle();

            // setters
            void setTorqueCurve(FunctionCurve3 torqueCurve);
            void setIdleRpm(int idleRpm);
            void setRpm(int rpm);
            void setThrottle(double throttle);

        private:
            // engine constants
            FunctionCurve3 torqueCurve; // torque curve is a function that returns the torque[Watt] at a given rpm
            int idleRpm;                // idleRpm is the rpm at which the engine is idling

            // engine variables
            int rpm;         // rpm is the current engine speed
            double throttle; // throttle is a value between 0 and 1 and is dependent on the driver
        };
    }
}

#endif