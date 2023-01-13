using System;
using System.Runtime.InteropServices;
using static cpv.Common.Common;

namespace cpv {
    public class FunctionCurve2 {
        FunctionCurve2()
        {
            __instance = FunctionCurve2_new();
            managed = true;
        }

        FunctionCurve2(IntPtr instance)
        {
            __instance = instance;
            managed = false;
        }

        ~FunctionCurve2()
        {
            if (managed)
            {
                FunctionCurve2_delete(__instance);
            }
        }

        public int NumberOfPoints
        {
            get
            {
                return FunctionCurve2_getNumberOfPoints(__instance);
            }
        }

        public Vector2 GetPoint(int index)
        {
            return new Vector2(FunctionCurve2_getPoint(__instance, index));
        }

        public void AddPoint(Vector2 point)
        {
            FunctionCurve2_AddPoint(__instance, point.__instance);
        }

        public void AddPoint(double x, double y)
        {
            FunctionCurve2_AddPointXY(__instance, x, y);
        }

        public void Clear()
        {
            FunctionCurve2_Clear(__instance);
        }


        public IntPtr __instance { get; }

        private readonly bool managed;

        [DllImport(DllName)]
        private static extern IntPtr FunctionCurve2_new();

        [DllImport(DllName)]
        private static extern void FunctionCurve2_delete(IntPtr ptr);

        [DllImport(DllName)]
        private static extern int FunctionCurve2_getNumberOfPoints(IntPtr ptr);

        [DllImport(DllName)]
        private static extern IntPtr FunctionCurve2_getPoint(IntPtr ptr, int index);

        [DllImport(DllName)]
        private static extern void FunctionCurve2_AddPoint(IntPtr ptr, IntPtr point);

        [DllImport(DllName)]
        private static extern void FunctionCurve2_AddPointXY(IntPtr ptr, double x, double y);

        [DllImport(DllName)]
        private static extern void FunctionCurve2_Clear(IntPtr ptr);
    }
}