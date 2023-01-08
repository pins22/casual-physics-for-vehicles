using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using static cpv.Common.Common;

namespace cpv
{
    class Vector2
    {
        public Vector2()
        {
            __instance = Vector2_new();
            managed = true;
        }

        public Vector2(IntPtr instance, bool managed = false)
        {
            this.__instance = instance;
            this.managed = managed;
        }

        ~Vector2()
        {
            if(managed)
            {
                Vector2_delete(__instance);
            }
        }

        public double X
        {
            get
            {
                return Vector2_getX(__instance);
            }
            set
            {
                Vector2_setX(__instance, value);
            }
        }

        public double Y
        {
            get
            {
                return Vector2_getY(__instance);
            }
            set
            {
                Vector2_setY(__instance, value);
            }
        }

        public double Magnitude
        {
            get
            {
                return Vector2_getMagnitude(__instance);
            }
        }

        public static Vector2 operator+(Vector2 a, Vector2 b) {
            return new Vector2(Vector2_add(a.__instance, b.__instance), true);
        }

        public static Vector2 operator-(Vector2 a, Vector2 b)
        {
            return new Vector2(Vector2_subtract(a.__instance, b.__instance), true);
        }

        public static Vector2 operator*(Vector2 a, double b)
        {
            return new Vector2(Vector2_multiply(a.__instance, b), true);
        }

        public static bool operator==(Vector2 a, Vector2 b)
        {
            return Vector2_equals(a.__instance, b.__instance);
        }

        public static bool operator !=(Vector2 a, Vector2 b)
        {
            return Vector2_notEquals(a.__instance, b.__instance);
        }

        public override bool Equals(object obj)
        {
            var vector = obj as Vector2;
            return vector != null && this == vector;
        }

        public override int GetHashCode()
        {
            return -162508190 + EqualityComparer<IntPtr>.Default.GetHashCode(__instance);
        }

        public IntPtr __instance { get; }

        private readonly bool managed;
        
        [DllImport(DllName)]
        private static extern IntPtr Vector2_new();

        [DllImport(DllName)]
        private static extern IntPtr Vector2_newData(double x, double y);

        [DllImport(DllName)]
        private static extern void Vector2_delete(IntPtr ptr);

        [DllImport(DllName)]
        private static extern double Vector2_getX(IntPtr ptr);
        
        [DllImport(DllName)]
        private static extern double Vector2_getY(IntPtr ptr);

        [DllImport(DllName)]
        private static extern void Vector2_setX(IntPtr ptr, double x);

        [DllImport(DllName)]
        private static extern void Vector2_setY(IntPtr ptr, double y);

        [DllImport(DllName)]
        private static extern double Vector2_getMagnitude(IntPtr ptr);

        [DllImport(DllName)]
        private static extern IntPtr Vector2_add(IntPtr ptr, IntPtr other);

        [DllImport(DllName)]
        private static extern IntPtr Vector2_subtract(IntPtr ptr, IntPtr other);

        [DllImport(DllName)]
        private static extern IntPtr Vector2_multiply(IntPtr ptr, double scalar);

        [DllImport(DllName)]
        private static extern bool Vector2_equals(IntPtr ptr, IntPtr other);

        [DllImport(DllName)]
        private static extern bool Vector2_notEquals(IntPtr ptr, IntPtr other);
    }
}
