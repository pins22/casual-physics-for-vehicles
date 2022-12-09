#ifndef CPV_FUNCTION_CURVE3_H
#define CPV_FUNCTION_CURVE3_H

#include <vector>
#include <stdlib.h>
#include "CpvFunctionCurve2.h"

namespace cpv
{
    /// @brief
    /// A class that represents a mathematical 3D function curve
    /// @details
    /// A function curve is a mathematical function that is defined by a set of points. The function curves are always aligned on the z axis.

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
         * @param curveFunctions the curve functions to use (must be sorted by x value)
         * @param zAxisForEachCurve the z axis value for each curve function in the curveFunctions vector
         */
        CpvFunctionCurve3(std::vector<CpvFunctionCurve2> curveFunctions, std::vector<double> zAxisForEachCurve) : curveFunctions(curveFunctions), zAxisForEachCurve(zAxisForEachCurve)
        {
            // Check that the curve functions and z axis values are the same size
            if (curveFunctions.size() != zAxisForEachCurve.size())
            {
                throw "The curve functions and z axis values must be the same size";
            }
        }

        /**
         * @brief Add a curve function to the curve on the specified z axis value
         *
         * @param curveFunction the curve function to add
         * @param zAxis the z axis value for the curve function
         */
        void addCurveFunction(CpvFunctionCurve2 curveFunction, double zAxis)
        {
            // Find the index to insert the curve function at
            auto index = std::lower_bound(zAxisForEachCurve.begin(), zAxisForEachCurve.end(), zAxis);

            // Insert the curve function at the index
            curveFunctions.insert(curveFunctions.begin() + (index - zAxisForEachCurve.begin()), curveFunction);
            zAxisForEachCurve.insert(index, zAxis);
        }

        /**
         * @brief Add a point to the curve function on the specified z axis value
         *
         * @param point the point to add
         * @param zAxis the z axis value for the curve function
         */
        void addPoint(CpvVector2 point, double zAxis)
        {
            // Find the index to insert the curve function at
            auto index = std::lower_bound(zAxisForEachCurve.begin(), zAxisForEachCurve.end(), zAxis);

            // Insert the point at the index
            curveFunctions[index - zAxisForEachCurve.begin()].addPoint(point);
        }

        /**
         * @brief Add a point to the curve function on the specified z axis value at the x and y values
         *
         * @param x the x value of the point to add
         * @param y the y value of the point to add
         * @param zAxis the z axis value for the curve function
         */
        void addPoint(double x, double y, double zAxis)
        {
            addPoint(CpvVector2(x, y), zAxis);
        }

        /**
         * @brief Get y value for the specified x and z values
         *
         * @param x the x value
         * @param z the z value
         * @return y value
         */
        double getYValue(double x, double z)
        {
            // Find the index of the curve function to use
            auto ptr = std::lower_bound(zAxisForEachCurve.begin(), zAxisForEachCurve.end(), z);

            // Get the curve function to use
            // - zAxosForEachCurve.begin() is used to get the index of the curve function, not the address
            CpvFunctionCurve2 curveFunction1 = curveFunctions[ptr - zAxisForEachCurve.begin()];
            CpvFunctionCurve2 curveFunction2 = curveFunctions[ptr - zAxisForEachCurve.begin() + 1];

            // Get the y values for the x value
            double y1 = curveFunction1.getYValue(x);
            double y2 = curveFunction2.getYValue(x);

            return std::abs(y2 - y1) / 2;
        }

        /**
         * @brief Get y value for the specified x and z values
         *
         * @param x the x value
         * @param z the z value
         * @return y value
         */
        double getYValue(int x, int z)
        {
            // Find the index of the curve function to use
            auto ptr = std::lower_bound(zAxisForEachCurve.begin(), zAxisForEachCurve.end(), z);

            // Get the curve function to use
            // - zAxosForEachCurve.begin() is used to get the index of the curve function, not the address
            CpvFunctionCurve2 curveFunction1 = curveFunctions[ptr - zAxisForEachCurve.begin()];
            CpvFunctionCurve2 curveFunction2 = curveFunctions[ptr - zAxisForEachCurve.begin() + 1];

            // Get the y values for the x value
            double y1 = curveFunction1.getYValue(x);
            double y2 = curveFunction2.getYValue(x);

            return std::abs(y2 - y1) / 2;
        }

        /**
         * @brief Clear the curve functions and z axis values
         */
        void clear()
        {
            curveFunctions.clear();
            zAxisForEachCurve.clear();
        }

    private:
        std::vector<CpvFunctionCurve2> curveFunctions;
        std::vector<double> zAxisForEachCurve;
    };
}

#endif