#pragma once
#include <cmath>

using namespace std;

namespace cpv
{
    class CpvVector2
    {
    public:
        /**
         * @brief Default constructor
         * @details Creates vector of (0, 0)
         */
        CpvVector2() : x(0), y(0) {}

        /**
         * @brief Constructor with x and y components of the vector
         */
        CpvVector2(double x, double y) : x(x), y(y) {}

        // getters
        double getX() const { return x; }
        double getY() const { return y; }

        // setters
        void setX(double x) { this->x = x; }
        void setY(double y) { this->y = y; }

        /**
         * @brief Returns magnitude of the vector
         * 
         * @return double the magnitude of the vector
         */
        double getMagnitude() const
        {
            return sqrt(x * x + y * y);
        }

        /**
         * @brief Add two vectors together and return resulting vector
         * 
         * @param other the vector to add to this vector
         * @return CpvVector2 the resulting vector
         */
        CpvVector2 operator+(const CpvVector2 &other) const
        {
            return CpvVector2(x + other.x, y + other.y);
        }

        /**
         * @brief Subtract two vectors and return resulting vector
         * 
         * @param other the vector to subtract from this vector
         * @return CpvVector2 the resulting vector
         */
        CpvVector2 operator-(const CpvVector2 &other) const
        {
            return CpvVector2(x - other.x, y - other.y);
        }

        /**
         * @brief Multiply vector by a scalar and return resulting vector
         * 
         * @param scalar the scalar to multiply the vector by
         * @return CpvVector2 the resulting vector
         */
        CpvVector2 operator*(double scalar) const
        {
            return CpvVector2(x * scalar, y * scalar);
        }
        
        /**
         * @brief Divide vector by a scalar and return resulting vector
         * 
         * @param other 
         * @return true 
         * @return bool 
         */
        bool operator==(const CpvVector2 &other) const
        {
            return x == other.x && y == other.y;
        }

        /**
         * @brief Compare two vectors and return true if they are not equal
         * 
         * @param other 
         * @return true 
         * @return bool 
         */
        bool operator!=(const CpvVector2 &other) const
        {
            return !(*this == other);
        }

        /**
         * @brief Compare two vectors and return true if this vector is less than the other vector
         * 
         * @param other
         * @return bool
         */
        bool operator<(const CpvVector2 &other) const
        {
            return x < other.x;
        }

    private:
        double x;
        double y;
    };
}
