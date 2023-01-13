using System;
using System.Runtime.InteropServices;
using static cpv.Common.Common;

namespace cpv {
    public class FunctionCurve3 {

        public FunctionCurve3()
        {
            instance = FunctionCurve3_new();
            managed = true;
        }

        public FunctionCurve3(IntPtr instance, bool managed = false)
        {
            this.instance = instance;
            this.managed = managed;
        }

        ~FunctionCurve3()
        {
            if (managed)
            {
                FunctionCurve3_delete(instance);
            }
        }

        public void AddCurveFunction(FunctionCurve2 curve, double z)
        {
            FunctionCurve3_addCurveFunction(instance, curve.__instance, z);
        }

        public void Clear()
        {
            FunctionCurve3_clear(instance);
        }

        private readonly IntPtr instance;
        private readonly bool managed;

        [DllImport(DllName)]
        private static extern IntPtr FunctionCurve3_new();

        [DllImport(DllName)]
        private static extern void FunctionCurve3_delete(IntPtr ptr);

        [DllImport(DllName)]
        private static extern void FunctionCurve3_addCurveFunction(IntPtr ptr, IntPtr curveFunction, double zAxis);

        [DllImport(DllName)]
        private static extern void FunctionCurve3_clear(IntPtr ptr);
    }
}