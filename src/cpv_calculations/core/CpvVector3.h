#ifndef CPV_VECTOR3_H
#define CPV_VECTOR3_H

#include <cmath>

using namespace std;

namespace cpv
{
    class CpvVector3
    {
    public:
        /**
         * @brief Default constructor
         * @details Creates vector of (0, 0, 0)
         */
        CpvVector3() : x(0), y(0), z(0) {}

        /**
         * @brief Constructor with x, y and z components of the vector
         * 
         * @param x the x component of the vector
         * @param y the y component of the vector
         * @param z the z component of the vector
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

        /**
         * @brief Returns magnitude of the vector
         * 
         * @return double the magnitude of the vector
         */
        double getMagnitude() const
        {
            return sqrt(x * x + y * y + z * z);
        }

        /**
         * @brief Add two vectors together and return resulting vector
         * 
         * @param other the vector to add to this vector
         * @return CpvVector3 the resulting vector
         */
        CpvVector3 operator+(const CpvVector3 &other) const
        {
            return CpvVector3(x + other.x, y + other.y, z + other.z);
        }

        /**
         * @brief Subtract two vectors and return resulting vector
         * 
         * @param other the vector to subtract from this vector
         * @return CpvVector3 the resulting vector
         */
        CpvVector3 operator-(const CpvVector3 &other) const
        {
            return CpvVector3(x - other.x, y - other.y, z - other.z);
        }

        /**
         * @brief Multiply vector by a scalar and return resulting vector
         * 
         * @param scalar the scalar to multiply the vector by
         * @return CpvVector3 the resulting vector
         */
        CpvVector3 operator*(double scalar) const
        {
            return CpvVector3(x * scalar, y * scalar, z * scalar);
        }

        /**
         * @brief Compare two vectors for equality
         * 
         * @param other the vector to compare to this vector
         * @return true if the vectors are equal
         * @return false if the vectors are not equal
         */
        bool operator==(const CpvVector3 &other) const
        {
            return x == other.x && y == other.y && z == other.z;
        }

        /**
         * @brief Compare two vectors for inequality
         * 
         * @param other the vector to compare to this vector
         * @return true if the vectors are not equal
         * @return false if the vectors are equal
         */
        bool operator!=(const CpvVector3 &other) const
        {
            return !(*this == other);
        }

    private:
        double x;
        double y;
        double z;
    };
}

#endif