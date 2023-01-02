using System;
using System.Runtime.InteropServices;
namespace cpv
{
    public class Transmission
    {
        public Transmission()
        {
            instance = IntPtr.Zero;
        }

        public Transmission(IntPtr instance)
        {
            this.instance = instance;
        }

        public double driveRatio
        {
            get
            {
                return Transmission_getFinalDriveRatio(instance);
            }

            set
            {
                Transmission_setFinalDriveRatio(instance, value);
            }
        }

        public int currentGear
        {
            get
            {
                return Transmission_getCurrentGear(instance);
            }
            set
            {
                Transmission_setCurrentGear(instance, value);
            }
        }

        public double[] gearRatios
        {
            set
            {
                Transmission_setGearRatios(instance, value, value.Length);
            }

            get
            {
                int size;
                IntPtr arr;

                Transmission_getGearRatios(instance, out arr, out size);
                double[] array = new double[size];
                Marshal.Copy(arr, array, 0, size);
                Marshal.FreeCoTaskMem(arr);

                return array;
            }
        }

        private IntPtr instance;

        [DllImport("libengine.dll")]
        private static extern void Transmission_setFinalDriveRatio(IntPtr transmission, double driveRatio);

        [DllImport("libengine.dll")]
        private static extern double Transmission_getFinalDriveRatio(IntPtr transmission);

        [DllImport("libengine.dll")]
        private static extern void Transmission_setCurrentGear(IntPtr transmission, int currentGear);

        [DllImport("libengine.dll")]
        private static extern int Transmission_getCurrentGear(IntPtr transmission);

        [DllImport("libengine.dll")]
        private static extern void Transmission_setGearRatios(IntPtr transmission, double[] ratios, int size);

        [DllImport("libengine.dll")]
        private static extern void Transmission_getGearRatios(IntPtr transmission, out IntPtr array, out int size);
    }
}
