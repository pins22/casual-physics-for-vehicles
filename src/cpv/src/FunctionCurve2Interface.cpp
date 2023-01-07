#include "common.h"
#include "core/FunctionCurve2.h"

extern "C"
{
    DLL_EXPORT cpv::FunctionCurve2 *FunctionCurve2_new()
    {
        return new cpv::FunctionCurve2();
    }

    DLL_EXPORT  void FunctionCurve2_delete(cpv::FunctionCurve2 *functionCurve2)
    {
        delete functionCurve2;
    }

    DLL_EXPORT int FunctionCurve2_getNumberOfPoints(cpv::FunctionCurve2 *functionCurve2)
    {
        if (functionCurve2)
        {
            return functionCurve2->getNumberOfPoints();
        }

        return 0;
    }

    DLL_EXPORT cpv::Vector2* FunctionCurve2_getPoint(cpv::FunctionCurve2 *functionCurve2, int index)
    {
        if (functionCurve2)
        {
            return new cpv::Vector2(functionCurve2->getPoint(index));
        }

        return new cpv::Vector2();
    }

    DLL_EXPORT void FunctionCurve2_AddPoint(cpv::FunctionCurve2 *functionCurve2, cpv::Vector2 *point)
    {
        if (functionCurve2 && point)
        {
            functionCurve2->addPoint(*point);
        }
    }

    DLL_EXPORT void FunctionCurve2_AddPointXY(cpv::FunctionCurve2 *functionCurve2, double x, double y)
    {
        if (functionCurve2)
        {
            functionCurve2->addPoint(x, y);
        }
    }

    DLL_EXPORT void FunctionCurve2_Clear(cpv::FunctionCurve2 *functionCurve2)
    {
        if (functionCurve2)
        {
            functionCurve2->clear();
        }
    }
}