using System;
using System.Runtime.InteropServices;

namespace cpv
{
    class Vector2
    {
        private const string dllName = "libengine.dll";
        
        [DllImport(dllName)]
        private static extern IntPtr Vector2_new();

        [DllImport(dllName)]
        private static extern IntPtr Vector2_newData(double x, double y);

        [DllImport(dllName)]
        private static extern void Vector2_delete(IntPtr ptr);

        [DllImport(dllName)]
        private static extern double Vector2_getX(IntPtr ptr);
        
        [DllImport(dllName)]
        private static extern double Vector2_getY(IntPtr ptr);

        [DllImport(dllName)]
        private static extern void Vector2_setX(IntPtr ptr, double x);

        [DllImport(dllName)]
        private static extern void Vector2_setY(IntPtr ptr, double y);

        [DllImport(dllName)]
        private static extern double Vector2_getMagnitude(IntPtr ptr);

        [DllImport(dllName)]
        private static extern IntPtr Vector2_add(IntPtr ptr, IntPtr other);

        [DllImport(dllName)]
        private static extern IntPtr Vector2_subtract(IntPtr ptr, IntPtr other);

        [DllImport(dllName)]
        private static extern IntPtr Vector2_multiply(IntPtr ptr, double scalar);

        [DllImport(dllName)]
        private static extern bool Vector2_equals(IntPtr ptr, IntPtr other);

        [DllImport(dllName)]
        private static extern bool Vector2_notEquals(IntPtr ptr, IntPtr other);
        
    }
}
