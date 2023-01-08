using System;
using System.Runtime.InteropServices;
using static cpv.Common.Common;

namespace cpv
{
    public class MainEngine
    {
        public MainEngine()
        {
            instance = MainEngine_new();
            engineInstance = MainEngine_getEngine(instance);
            brakeInstance = MainEngine_getBrake(instance);
            transmissionInstance = MainEngine_getTransmission(instance);

            vehicleEngine = new VehicleEngine(engineInstance);
            brake = new Brake(brakeInstance);
            transmission = new Transmission(transmissionInstance);
        }

        ~MainEngine()
        {
            MainEngine_delete(instance);
            instance = IntPtr.Zero;
        }

        public void Initialize(string initJson)
        {
            MainEngine_initialize(instance, initJson);
        }

        public double CalculateLongitudinalForce(double velocity, double slope, double brakeAmount)
        {
            return MainEngine_calculateLongitudinalForce(instance, velocity, slope, brakeAmount);
        }

        private readonly IntPtr engineInstance;
        private readonly IntPtr brakeInstance;
        private readonly IntPtr transmissionInstance;
        private readonly IntPtr longitudinalForceModelInstance;
        private IntPtr instance;

        public VehicleEngine vehicleEngine;
        public Brake brake;
        public Transmission transmission;

        [DllImport(DllName)]
        private static extern IntPtr MainEngine_new();

        [DllImport(DllName)]
        private static extern void MainEngine_delete(IntPtr engine);

        [DllImport(DllName)]
        private static extern void MainEngine_initialize(IntPtr engine, String str);

        [DllImport(DllName)]
        private static extern IntPtr MainEngine_getEngine(IntPtr engine);

        [DllImport(DllName)]
        private static extern IntPtr MainEngine_getBrake(IntPtr engine);

        [DllImport(DllName)]
        private static extern IntPtr MainEngine_getTransmission(IntPtr engine);

        [DllImport(DllName)]
        private static extern IntPtr MainEngine_getLongitudinalForceModel(IntPtr engine);

        [DllImport(DllName)]
        private static extern double MainEngine_calculateLongitudinalForce(IntPtr engine, double velocity, double slope, double brakeAmount);
    }
}
