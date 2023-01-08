using System;
using System.Runtime.InteropServices;
using static cpv.Common.Common;

namespace cpv
{
    public class Brake
    {
        public Brake(bool managed = true)
        {
            if(managed)
            {
                instance = Brake_new();
            }
            this.managed = managed;
        }

        public Brake(IntPtr instance, bool managed = false)
        {
            this.instance = instance;
            this.managed = managed;
        }

        ~Brake()
        {
            if(managed)
            {
                Brake_delete(instance);
            }
        }

        public double MaxBrakeTorque
        {
            get
            {
                return Brake_getMaxBrakeTorque(instance);
            }

            set
            {
                Brake_setMaxBrakeTorque(instance, value);
            }
        }

        private readonly IntPtr instance;
        private readonly bool managed;

        [DllImport(DllName)]
        private static extern IntPtr Brake_new();

        [DllImport(DllName)]
        private static extern void Brake_delete(IntPtr brake);

        [DllImport(DllName)]
        private static extern void Brake_setMaxBrakeTorque(IntPtr brake, double maxBrakeTorque);

        [DllImport(DllName)]
        private static extern double Brake_getMaxBrakeTorque(IntPtr brake);
    }
}
