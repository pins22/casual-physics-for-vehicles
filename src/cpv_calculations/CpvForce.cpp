#include <cmath>

using namespace std;

namespace cpv
{
    class CpvForce
    {
    public:
        /*
         * Default constructor
         * Creates force of (0, 0, 0)
         */
        CpvForce() : x(0), y(0), z(0) {}

        /*
         * Constructor with x, y and z components of the force
         */
        CpvForce(double x, double y, double z) : x(x), y(y), z(z) {}

        /*
         * Returns magnitude of the force
         */
        double getMagnitude() const
        {
            return sqrt(x * x + y * y + z * z);
        }

        /*
         * Add two forces together and return resulting force
         */
        CpvForce operator+(const CpvForce &other) const
        {
            return CpvForce(x + other.x, y + other.y, z + other.z);
        }

        /*
         * Subtract two forces and return resulting force
         */
        CpvForce operator-(const CpvForce &other) const
        {
            return CpvForce(x - other.x, y - other.y, z - other.z);
        }

        /*
         * Multiply force by a scalar and return resulting force
         */
        CpvForce operator*(double scalar) const
        {
            return CpvForce(x * scalar, y * scalar, z * scalar);
        }

    private:
        double x;
        double y;
        double z;
    };
}