#include <cmath>

using namespace std;

namespace cpv
{
    class CpvVector3
    {
    public:
        /*
         * Default constructor
         * Creates force of (0, 0, 0)
         */
        CpvVector3() : x(0), y(0), z(0) {}

        /*
         * Constructor with x, y and z components of the force
         */
        CpvVector3(double x, double y, double z) : x(x), y(y), z(z) {}

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
        CpvVector3 operator+(const CpvVector3 &other) const
        {
            return CpvVector3(x + other.x, y + other.y, z + other.z);
        }

        /*
         * Subtract two forces and return resulting force
         */
        CpvVector3 operator-(const CpvVector3 &other) const
        {
            return CpvVector3(x - other.x, y - other.y, z - other.z);
        }

        /*
         * Multiply force by a scalar and return resulting force
         */
        CpvVector3 operator*(double scalar) const
        {
            return CpvVector3(x * scalar, y * scalar, z * scalar);
        }

    private:
        double x;
        double y;
        double z;
    };
}