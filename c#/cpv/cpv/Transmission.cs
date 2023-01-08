using System;
using System.Runtime.InteropServices;
using static cpv.Common.Common;

namespace cpv
{
    public class Transmission
    {
        public Transmission()
        {
            instance = Transmission_new();
            managed = true;
        }

        public Transmission(IntPtr instance, bool managed = false)
        { 
            this.instance = instance;
            this.managed = managed;
        }

        ~Transmission()
        {
            if (managed)
            {
                Transmission_delete(instance);
            }
        }

        public double DriveRatio
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

        public int CurrentGear
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

        public double[] GearRatios
        {
            set
            {
                Transmission_setGearRatios(instance, value, value.Length);
            }

            get
            {

                Transmission_getGearRatios(instance, out IntPtr arr, out int size);
                double[] array = new double[size];
                Marshal.Copy(arr, array, 0, size);
                Marshal.FreeCoTaskMem(arr);

                return array;
            }
        }

        private readonly IntPtr instance;
        private readonly bool managed;

        [DllImport(DllName)]
        private static extern IntPtr Transmission_new();

        [DllImport(DllName)]
        private static extern void Transmission_delete(IntPtr transmission);

        [DllImport(DllName)]
        private static extern void Transmission_setFinalDriveRatio(IntPtr transmission, double driveRatio);

        [DllImport(DllName)]
        private static extern double Transmission_getFinalDriveRatio(IntPtr transmission);

        [DllImport(DllName)]
        private static extern void Transmission_setCurrentGear(IntPtr transmission, int currentGear);

        [DllImport(DllName)]
        private static extern int Transmission_getCurrentGear(IntPtr transmission);

        [DllImport(DllName)]
        private static extern void Transmission_setGearRatios(IntPtr transmission, double[] ratios, int size);

        [DllImport(DllName)]
        private static extern void Transmission_getGearRatios(IntPtr transmission, out IntPtr array, out int size);
    }
}
