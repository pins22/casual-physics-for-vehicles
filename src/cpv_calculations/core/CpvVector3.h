#include <cmath>

using namespace std;

namespace cpv
{
    class CpvVector3
    {
    public:
        /*
         * Default constructor
         * Creates vector of (0, 0, 0)
         */
        CpvVector3() : x(0), y(0), z(0) {}

        /*
         * Constructor with x, y and z components of the vector
         */
        CpvVector3(double x, double y, double z) : x(x), y(y), z(z) {}

        // getters
        double getX() const { return x; }
        double getY() const { return y; }
        double getZ() const { return z; }

        // setters
        void setX(double x) { this->x = x; }
        void setY(double y) { this->y = y; }
        void setZ(double z) { this->z = z; }

        /*
         * Returns magnitude of the vector
         */
        double getMagnitude() const
        {
            return sqrt(x * x + y * y + z * z);
        }

        /*
         * Add two vectors together and return resulting vector
         */
        CpvVector3 operator+(const CpvVector3 &other) const
        {
            return CpvVector3(x + other.x, y + other.y, z + other.z);
        }

        /*
         * Subtract two vectors and return resulting vector
         */
        CpvVector3 operator-(const CpvVector3 &other) const
        {
            return CpvVector3(x - other.x, y - other.y, z - other.z);
        }

        /*
         * Multiply vector by a scalar and return resulting vector
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