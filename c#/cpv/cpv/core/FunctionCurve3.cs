using System;
using System.Runtime.InteropServices;

namespace cpv {
    class FunctionCurve3 {
        private const string dllName = "libengine.dll";

        [DllImport(dllName)]
        private static extern IntPtr FunctionCurve3_new();

        [DllImport(dllName)]
        private static extern void FunctionCurve3_delete(IntPtr ptr);

        [DllImport(dllName)]
        private static extern void FunctionCurve3_addCurveFunction(IntPtr ptr, IntPtr curveFunction, double zAxis);

        [DllImport(dllName)]
        private static extern void FunctionCurve3_clear(IntPtr ptr);
    }
}