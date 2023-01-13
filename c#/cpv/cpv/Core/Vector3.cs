using System;
using System.Runtime.InteropServices;
using static cpv.Common.Common;

namespace cpv {
    public class Vector3 {

        public Vector3()
        {
            instance = Vector3_new();
            managed = true;
        }

        public Vector3(double x, double y, double z)
        {
            instance = Vector3_newData(x, y, z);
            managed = true;
        }

        public Vector3(IntPtr instance, bool managed = false)
        {
            this.instance = instance;
            this.managed = managed;
        }

        ~Vector3()
        {
            if(managed)
            {
                Vector3_delete(instance);
            }
        }

        public double X
        {
            get
            {
                return Vector3_getX(instance);
            }

            set
            {
                Vector3_setX(instance, value);
            }
        }

        public double Y
        {
            get
            {
                return Vector3_getY(instance);
            }
            set
            {
                Vector3_setY(instance, value);
            }
        }

        public double Z
        {
            get
            {
                return Vector3_getZ(instance);
            }

            set
            {
                Vector3_setZ(instance, value);
            }
        }

        public double Magnitude
        {
            get
            {
                return Vector3_getMagnitude(instance);
            }
        }

        public static Vector3 operator+(Vector3 a, Vector3 b)
        {
            return new Vector3(Vector3_add(a.instance, b.instance), true);
        }

        public static Vector3 operator-(Vector3 a, Vector3 b)
        {
            return new Vector3(Vector3_subtract(a.instance, b.instance), true);
        }

        public static Vector3 operator*(Vector3 a, double b)
        {
            return new Vector3(Vector3_multiply(a.instance, b), true);
        }

        private readonly IntPtr instance;
        private readonly bool managed;

        [DllImport(DllName)]
        private static extern IntPtr Vector3_new();
        
        [DllImport(DllName)]
        private static extern IntPtr Vector3_newData(double x, double y, double z);
        
        [DllImport(DllName)]
        private static extern void Vector3_delete(IntPtr ptr);
        
        [DllImport(DllName)]
        private static extern double Vector3_getX(IntPtr ptr);
        
        [DllImport(DllName)]
        private static extern double Vector3_getY(IntPtr ptr);
        
        [DllImport(DllName)]
        private static extern double Vector3_getZ(IntPtr ptr);
        
        [DllImport(DllName)]
        private static extern void Vector3_setX(IntPtr ptr, double x);
        
        [DllImport(DllName)]
        private static extern void Vector3_setY(IntPtr ptr, double y);

        [DllImport(DllName)]
        private static extern void Vector3_setZ(IntPtr ptr, double z);
        
        [DllImport(DllName)]
        private static extern double Vector3_getMagnitude(IntPtr ptr);
        
        [DllImport(DllName)]
        private static extern IntPtr Vector3_add(IntPtr ptr, IntPtr other);
        
        [DllImport(DllName)]
        private static extern IntPtr Vector3_subtract(IntPtr ptr, IntPtr other);
        
        [DllImport(DllName)]
        private static extern IntPtr Vector3_multiply(IntPtr ptr, double scalar);
        
        [DllImport(DllName)]
        private static extern bool Vector3_equals(IntPtr ptr, IntPtr other);

        [DllImport(DllName)]
        private static extern bool Vector3_notEquals(IntPtr ptr, IntPtr other);
    }
}
