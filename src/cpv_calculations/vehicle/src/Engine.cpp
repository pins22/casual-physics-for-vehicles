#include "vehicle/powertrain/Engine.h"
#include "core/FunctionCurve3.h"

namespace cpv
{
    namespace vehicle
    {
        // engine constants
        FunctionCurve3 torqueCurve; // torque curve is a function that returns the torque[Watt] at a given rpm
        int idleRpm;                // idleRpm is the rpm at which the engine is idling
        int maxRpm;                 // maxRpm is the maximum rpm of the engine

        // engine variables
        int rpm;         // rpm is the current engine speed
        double throttle; // throttle is a value between 0 and 1 and is dependent on the driver

        // Default constructor for the CpvEngine class
        // Sets all values to 0
        Engine::Engine()
        {
            torqueCurve = FunctionCurve3();
            idleRpm = 0;
            maxRpm = 0;
            rpm = 0;
            throttle = 0.0;
        }

        // Basic constructor for the CpvEngine class
        // Sets all values to the given values
        Engine::Engine(FunctionCurve3 torqueCurve, int idleRpm, int maxRpm)
        {
            this->torqueCurve = torqueCurve;
            this->idleRpm = idleRpm;
            this->maxRpm = maxRpm;
            this->rpm = 0;
            this->throttle = 0.0;
        }

        // Assignment operator for the CpvEngine class
        Engine &Engine::operator=(const Engine &other)
        {
            if (this != &other)
            {
                torqueCurve = other.torqueCurve;
                idleRpm = other.idleRpm;
                rpm = other.rpm;
                throttle = other.throttle;
            }
            return *this;
        }

        // Calculate the torque [N*m] at the current rpm and throttle
        double Engine::calculateTorque()
        {
            return torqueCurve.getYValue(1.0 * rpm, throttle);
        }

        // Calculate the power [Watt] at the current rpm and throttle
        double Engine::calculatePower()
        {
            return torqueCurve.getYValue(1.0 * rpm, throttle) * rpm / 9549.0;
        }

        // getters
        FunctionCurve3 Engine::getTorqueCurve()
        {
            return torqueCurve;
        }

        int Engine::getIdleRpm()
        {
            return idleRpm;
        }

        int Engine::getMaxRpm()
        {
            return maxRpm;
        }

        int Engine::getRpm()
        {
            return rpm;
        }

        double Engine::getThrottle()
        {
            return throttle;
        }

        // setters
        void Engine::setTorqueCurve(FunctionCurve3 torqueCurve)
        {
            this->torqueCurve = torqueCurve;
        }

        void Engine::setIdleRpm(int idleRpm)
        {
            this->idleRpm = idleRpm;
        }

        void Engine::setMaxRpm(int maxRpm)
        {
            this->maxRpm = maxRpm;
        }

        void Engine::setRpm(int rpm)
        {
            this->rpm = rpm;
        }

        void Engine::setThrottle(double throttle)
        {
            this->throttle = throttle;
        }

    }
}