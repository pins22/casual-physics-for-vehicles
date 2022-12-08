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
         * @param points the vector of points to use (must be sorted by x value)
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
            // Find the index to insert the point at
            auto index = std::lower_bound(points.begin(), points.end(), point);

            // Insert the point at the index
            points.insert(index, point);
        }

        /**
         * @brief Adds a point to the function curve with the specified x and y values
         *
         * @param x the x value of the point
         * @param y the y value of the point
         */
        void addPoint(double x, double y)
        {
            addPoint(CpvVector2(x, y));
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

            // If the x value equalse the first point, return the y value of the first point
            if (x == points[0].getX())
                return points[0].getY();

            //
            // TODO: create custom exceptions
            //

            // If the x value is less than the first point, throw an exception
            if (x < points[0].getX())
                throw "The x value is less than the first point in the function curve";

            // If the x value is greater than the last point, throw an exception
            if (x > points[points.size() - 1].getX())
                throw "The x value is greater than the last point in the function curve";

            auto index = std::lower_bound(points.begin(), points.end(), CpvVector2(x, 0));

            // If the x value is equal to a point, return the y value of the point
            if (x == index->getX())
                return index->getY();

            // Get the x and y values of the two points that the x value is between

            double y1 = index->getY();
            double y2 = (index - 1)->getY();

            return std::abs(y2 - y1) / 2;
        }

    private:
        std::vector<CpvVector2> points;
    };
}

#endif