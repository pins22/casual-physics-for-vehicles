#ifndef CPV_FUNCTION_CURVE_H
#define CPV_FUNCTION_CURVE_H

#include <vector>
#include <stdlib.h>
#include "CpvVector2.h"

namespace cpv
{
    class CpvFunctionCurve
    {
    public:
        /*
         * Default constructor
         * Creates an empty function curve
         */
        CpvFunctionCurve() {}

        /*
         * Constructor with a vector of points
         */
        CpvFunctionCurve(std::vector<CpvVector2> points) : points(points) {}

        /*
         * Returns the number of points in the function curve
         */
        int getNumberOfPoints() const
        {
            return points.size();
        }

        /*
         * Returns the point at the specified index
         */
        CpvVector2 getPoint(int index) const
        {
            return points[index];
        }

        /*
         * Adds a point to the function curve with the specified vector point
         */
        void addPoint(CpvVector2 point)
        {
            points.push_back(point);
        }

        /*
         * Adds a point to the function curve with the specified x and y values
         */
        void addPoint(double x, double y)
        {
            points.push_back(CpvVector2(x, y));
        }

        /*
         * Removes the point at the specified index
         */
        void removePoint(int index)
        {
            points.erase(points.begin() + index);
        }

        /*
         * Removes all points from the function curve
         */
        void clear()
        {
            points.clear();
        }

        /*
         * Returns the value of the function curve at the specified x value
         */
        double getValue(double x) const
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