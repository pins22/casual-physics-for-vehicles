using System;
using System.Runtime.InteropServices;

namespace cpv {
    class Vector3 {
        private const string dllName = "libengine.dll";
        
        [DllImport(dllName)]
        private static extern IntPtr Vector3_new();
        
        [DllImport(dllName)]
        private static extern IntPtr Vector3_newData(double x, double y, double z);
        
        [DllImport(dllName)]
        private static extern void Vector3_delete(IntPtr ptr);
        
        [DllImport(dllName)]
        private static extern double Vector3_getX(IntPtr ptr);
        
        [DllImport(dllName)]
        private static extern double Vector3_getY(IntPtr ptr);
        
        [DllImport(dllName)]
        private static extern double Vector3_getZ(IntPtr ptr);
        
        [DllImport(dllName)]
        private static extern void Vector3_setX(IntPtr ptr, double x);
        
        [DllImport(dllName)]
        private static extern void Vector3_setY(IntPtr ptr, double y);
        
        [DllImport(dllName)]
        private static extern void Vector3_setZ(IntPtr ptr, double z);
        
        [DllImport(dllName)]
        private static extern double Vector3_getMagnitude(IntPtr ptr);
        
        [DllImport(dllName)]
        private static extern IntPtr Vector3_add(IntPtr ptr, IntPtr other);
        
        [DllImport(dllName)]
        private static extern IntPtr Vector3_subtract(IntPtr ptr, IntPtr other);
        
        [DllImport(dllName)]
        private static extern IntPtr Vector3_multiply(IntPtr ptr, double scalar);
        
        [DllImport(dllName)]
        private static extern bool Vector3_equals(IntPtr ptr, IntPtr other);
    }
}
