#ifndef CPV_FUNCTION_CURVE2_H
#define CPV_FUNCTION_CURVE2_H

#include <vector>
#include <stdlib.h>
#include "CpvVector2.h"

namespace cpv
{
    class CpvFunctionCurve2
    {
    public:
        /**
         * @brief Default constructor
         * Creates an empty function curve
         */
        CpvFunctionCurve2() {}

        /**
         * @brief Constructor with a vector of points
         * 
         * @param points the vector of points to use
         * 
         */
        CpvFunctionCurve2(std::vector<CpvVector2> points) : points(points) {}

        /**
         * @brief Returns the number of points in the function curve
         * 
         * @return int the number of points in the function curve
         */
        int getNumberOfPoints() const
        {
            return points.size();
        }

        /**
         * @brief Returns the point at the specified index
         * 
         * @param index the index of the point to return
         * @return CpvVector2 the point at the specified index
         */
        CpvVector2 getPoint(int index) const
        {
            return points[index];
        }

        /**
         * @brief Adds a point to the function curve with the specified vector point
         * 
         * @param point the point to add
         */
        void addPoint(CpvVector2 point)
        {
            points.push_back(point);
        }

        /**
         * @brief Adds a point to the function curve with the specified x and y values
         * 
         * @param x the x value of the point
         * @param y the y value of the point
         */
        void addPoint(double x, double y)
        {
            points.push_back(CpvVector2(x, y));
        }

        /**
         * @brief Removes the point at the specified index
         * 
         * @param index the index of the point to remove
         */
        void removePoint(int index)
        {
            points.erase(points.begin() + index);
        }

        /**
         * @brief Removes all points from the function curve
         */
        void clear()
        {
            points.clear();
        }

        /**
         * @brief Returns the value of the function curve at the specified x value
         * 
         * @param x the x value to get the y value for
         * @return double the y value of the function curve at the specified x value
         */
        double getYValue(double x) const
        {
            // If the function curve is empty, return 0
            if (points.size() == 0)
                return 0;

            //
            // TODO: create custom exceptions
            //

            // If the x value is less than the first point, throw an exception
            if (x < points[0].getX())
                throw "The x value is less than the first point in the function curve";

            // If the x value is greater than the last point, throw an exception
            if (x > points[points.size() - 1].getX())
                throw "The x value is greater than the last point in the function curve";

            // Find the two points that the x value is between
            int index = 0;
            while (x > points[index].getX())
                index++;

            // Calculate the value of the function curve at the specified x value between the two points
            double x1 = points[index - 1].getX();
            double y1 = points[index - 1].getY();
            double x2 = points[index].getX();
            double y2 = points[index].getY();

            double k = (y2 - y1) / (x2 - x1);
            double b = y1 - k * x1;

            return k * x + b;
        }

    private:
        std::vector<CpvVector2> points;
    };
}

#endif