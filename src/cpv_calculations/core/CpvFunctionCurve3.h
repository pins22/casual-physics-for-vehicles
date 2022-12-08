#ifndef CPV_FUNCTION_CURVE3_H
#define CPV_FUNCTION_CURVE3_H

#include <vector>
#include <stdlib.h>
#include "CpvVector3.h"

namespace cpv
{
    /// @brief
    /// A class that represents a mathematical 3D function curve
    /// @details
    /// A function curve is a mathematical function that is defined by a set of points

    class CpvFunctionCurve3
    {
    public:
        /**
         * @brief Construct a new Cpv Function Curve 3 object
         */
        CpvFunctionCurve3() {}

        /**
         * @brief Construct a new Cpv Function Curve 3 object
         *
         * @param points
         */
        CpvFunctionCurve3(std::vector<CpvVector3> points) : points(points) {}

        /**
         * @brief Get the Number Of Points object
         *
         * @return * Returns
         */
        int getNumberOfPoints() const
        {
            return points.size();
        }

        /**
         * @brief Get the Point object
         *
         * @param index
         * @return CpvVector3
         */
        CpvVector3 getPoint(int index) const
        {
            return points[index];
        }

        /**
         * @brief Add a point to the function curve
         * @details Adds a point of type CpvVector3 to the function 
         * 
         * @param point
         */
        void addPoint(CpvVector3 point)
        {
            points.push_back(point);
        }

        /**
         * @brief Add a point to the function curve
         * @details Adds a point to the function curve with the specified x, y, and z values
         * 
         * @param x 
         * @param y 
         * @param z 
         */
        void addPoint(double x, double y, double z)
        {
            points.push_back(CpvVector3(x, y, z));
        }

        /**
         * @brief Remove a point from the function curve
         * 
         * @param index 
         */
        void removePoint(int index)
        {
            points.erase(points.begin() + index);
        }

        /**
         * @brief Get the Y Value object
         * @details Gets the y value of the function curve at the specified x and z values
         * 
         * @param x 
         * @param z 
         * @return double 
         */
        double getYValue(double x, double z) const
        {
            // find the two points that the x value is between
            int xIndex = 0;
            while (xIndex < points.size() && points[xIndex].getX() < x)
            {
                xIndex++;
            }

            // find the two points that the z value is between
            int yIndex = 0;
            while (yIndex < points.size() && points[yIndex].getZ() < z)
            {
                yIndex++;
            }
        }

    private:
        std::vector<CpvVector3> points;
    };
}

#endif