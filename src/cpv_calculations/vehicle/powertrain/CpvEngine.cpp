#include "cpv_calculations/vehicle/powertrain/CpvEngine.h"
#include "cpv_calculations/core/CpvFunctionCurve3.h"

namespace cpv
{
    namespace vehicle
    {
        // engine constants
        CpvFunctionCurve3 torqueCurve; // torque curve is a function that returns the torque[Watt] at a given rpm
        int idleRpm;                   // idleRpm is the rpm at which the engine is idling

        // engine variables
        int rpm;         // rpm is the current engine speed
        double throttle; // throttle is a value between 0 and 1 and is dependent on the driver

        // Default constructor for the CpvEngine class
        // Sets all values to 0
        CpvEngine::CpvEngine()
        {
            torqueCurve = CpvFunctionCurve3();
            idleRpm = 0.0;
            rpm = 0.0;
            throttle = 0.0;
        }

        // Basic constructor for the CpvEngine class
        // Sets all values to the given values
        CpvEngine::CpvEngine(CpvFunctionCurve3 torqueCurve, int idleRpm)
        {
            this->torqueCurve = torqueCurve;
            this->idleRpm = idleRpm;
            this->rpm = 0.0;
            this->throttle = 0.0;
        }

        // Assignment operator for the CpvEngine class
        CpvEngine &CpvEngine::operator=(const CpvEngine &other)
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
        double CpvEngine::calculateTorque() const
        {
            return torqueCurve.getYValue(rpm, throttle);
        }

        // Calculate the power [Watt] at the current rpm and throttle
        double CpvEngine::calculatePower() const
        {
            return torqueCurve.getYValue(rpm, throttle) * rpm / 9549.0;
        }

        // getters
        CpvFunctionCurve3 CpvEngine::getTorqueCurve()
        {
            return torqueCurve;
        }

        int CpvEngine::getIdleRpm()
        {
            return idleRpm;
        }

        int CpvEngine::getRpm()
        {
            return rpm;
        }

        double CpvEngine::getThrottle()
        {
            return throttle;
        }

        // setters
        void CpvEngine::setTorqueCurve(CpvFunctionCurve3 torqueCurve)
        {
            this->torqueCurve = torqueCurve;
        }

        void CpvEngine::setIdleRpm(int idleRpm)
        {
            this->idleRpm = idleRpm;
        }

        void CpvEngine::setRpm(int rpm)
        {
            this->rpm = rpm;
        }

        void CpvEngine::setThrottle(double throttle)
        {
            this->throttle = throttle;
        }

    }
}