using System;
using System.Runtime.InteropServices;

namespace cpv
{
    public class Brake
    {
        public Brake()
        {
        }

        public Brake(IntPtr instance)
        {
            this.instance = instance;
        }

        double maxBrakeTorque
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

        private IntPtr instance;

        [DllImport("libengine.dll")]
        private static extern void Brake_setMaxBrakeTorque(IntPtr brake, double maxBrakeTorque);

        [DllImport("libengine.dll")]
        private static extern double Brake_getMaxBrakeTorque(IntPtr brake);
    }
}
