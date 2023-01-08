#include "common.h"
#include "core/FunctionCurve3.h"

extern "C"
{
    DLL_EXPORT cpv::FunctionCurve3 *FunctionCurve3_new()
    {
        return new cpv::FunctionCurve3();
    }

    DLL_EXPORT void FunctionCurve3_delete(cpv::FunctionCurve3 *functionCurve3)
    {
        delete functionCurve3;
    }

    DLL_EXPORT void FunctionCurve3_addCurveFunction(cpv::FunctionCurve3 *functionCurve3, cpv::FunctionCurve2* curve, double zAxis)
    {
        if(functionCurve3)
        {
            functionCurve3->addCurveFunction(*curve, zAxis);
        }
    }

    DLL_EXPORT void FunctionCurve3_clear(cpv::FunctionCurve3 *functionCurve3)
    {
        if(functionCurve3)
        {
            functionCurve3->clear();
        }
    }
}
