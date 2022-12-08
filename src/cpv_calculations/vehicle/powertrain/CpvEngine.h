#ifndef CPV_ENGINE_H
#define CPV_ENGINE_h

#include "cpv_calculations/core/CpvFunctionCurve3.h"

namespace cpv
{
    namespace vehicle
    {

        class CpvEngine
        {
        public:
            /**
             * @brief Default constructor for the CpvEngine class
             * @details Sets all values to 0
             */
            CpvEngine();

            /**
             * @brief Basic constructor for the CpvEngine class
             * @details Sets all values to the given values
             * 
             * @param torqueCurve the torque curve of the engine
             * @param powerCurve the power curve of the engine
             * @param idleRpm the idle rpm of the engine
             */
            CpvEngine(CpvFunctionCurve3 torqueCurve, int idleRpm);

            /**
             * @brief Assignment operator for the CpvEngine class
             * 
             * @param other the CpvEngine to copy
             * @return a reference to the CpvEngine
             */
            CpvEngine &operator=(const CpvEngine &other);

            /**
             * @brief Calculate the torque[N*m] at the current rpm and throttle
             * 
             * @return the torque at the current rpm and throttle
             */
            double calculateTorque() const;

            /**
             * @brief Calculate the power[Watt] at the current rpm and throttle
             * 
             * @return the power at the current rpm and throttle
             */
            double calculatePower() const;

            /**
             * @brief Calculate redline rpm
             * 
             * @return the redline rpm
             */

            // getters
            CpvFunctionCurve3 getTorqueCurve();
            int getIdleRpm();
            int getRpm();
            double getThrottle();

            // setters
            void setTorqueCurve(CpvFunctionCurve3 torqueCurve);
            void setIdleRpm(int idleRpm);
            void setRpm(int rpm);
            void setThrottle(double throttle);

        private:
            // engine constants
            CpvFunctionCurve3 torqueCurve; // torque curve is a function that returns the torque[Watt] at a given rpm
            int idleRpm;                // idleRpm is the rpm at which the engine is idling

            // engine variables
            int rpm;      // rpm is the current engine speed
            double throttle; // throttle is a value between 0 and 1 and is dependent on the driver
        };
    }
}

#endif