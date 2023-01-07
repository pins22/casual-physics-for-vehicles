using System;
using System.Runtime.InteropServices;

namespace cpv {
    class FunctionCurve2 {
        private const string dllName = "libengine.dll";

        [DllImport(dllName)]
        private static extern IntPtr FunctionCurve2_new();

        [DllImport(dllName)]
        private static extern void FunctionCurve2_delete(IntPtr ptr);

        [DllImport(dllName)]
        private static extern int FunctionCurve2_getNumberOfPoints(IntPtr ptr);

        [DllImport(dllName)]
        private static extern IntPtr FunctionCurve2_getPoint(IntPtr ptr, int index);

        [DllImport(dllName)]
        private static extern void FunctionCurve2_AddPoint(IntPtr ptr, IntPtr point);

        [DllImport(dllName)]
        private static extern void FunctionCurve2_AddPointXY(IntPtr ptr, double x, double y);

        [DllImport(dllName)]
        private static extern void FunctionCurve2_Clear(IntPtr ptr);
    }
}