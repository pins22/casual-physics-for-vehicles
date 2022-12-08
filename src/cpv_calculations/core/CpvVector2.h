#ifndef CPV_VECTOR2_H
#define CPV_VECTOR2_H

#include <cmath>

using namespace std;

namespace cpv
{
    class CpvVector2
    {
    public:
        /*
         * Default constructor
         * Creates vector of (0, 0)
         */
        CpvVector2() : x(0), y(0) {}

        /*
         * Constructor with x and y components of the vector
         */
        CpvVector2(double x, double y) : x(x), y(y) {}

        // getters
        double getX() const { return x; }
        double getY() const { return y; }

        // setters
        void setX(double x) { this->x = x; }
        void setY(double y) { this->y = y; }

        /*
         * Returns magnitude of the vector
         */
        double getMagnitude() const
        {
            return sqrt(x * x + y * y);
        }

        /*
         * Add two vectors together and return resulting vector
         */
        CpvVector2 operator+(const CpvVector2 &other) const
        {
            return CpvVector2(x + other.x, y + other.y);
        }

        /*
         * Subtract two vectors and return resulting vector
         */
        CpvVector2 operator-(const CpvVector2 &other) const
        {
            return CpvVector2(x - other.x, y - other.y);
        }

        /*
         * Multiply vector by a scalar and return resulting vector
         */
        CpvVector2 operator*(double scalar) const
        {
            return CpvVector2(x * scalar, y * scalar);
        }

    private:
        double x;
        double y;
    };
}

#endif