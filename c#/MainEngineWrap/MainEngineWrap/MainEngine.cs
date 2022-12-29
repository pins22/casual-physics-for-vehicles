using System;
using System.Runtime.InteropServices;

namespace cpv
{
    public class MainEngine
    {
        public MainEngine()
        {
            instance = MainEngine_new();
            engineInstance = MainEngine_getEngine(instance);
            brakeInstance = MainEngine_getBrake(instance);  
            vehicleEngine = new VehicleEngine(engineInstance);
            brake = new Brake(brakeInstance);
        }

        ~MainEngine()
        {
            MainEngine_delete(instance);
            instance = IntPtr.Zero;
        }

        public void initialize(string initJson)
        {
            MainEngine_initialize(instance, initJson);
        }

        private IntPtr engineInstance;
        private IntPtr brakeInstance;
        private IntPtr longitudinalForceModelInstance;
        private IntPtr instance;
        public VehicleEngine vehicleEngine;
        public Brake brake;

        [DllImport("libengine.so")]
        private static extern IntPtr MainEngine_new();

        [DllImport("libengine.so")]
        private static extern void MainEngine_delete(IntPtr engine);

        [DllImport("libengine.so")]
        private static extern void MainEngine_initialize(IntPtr engine, String str);

        [DllImport("libengine.so")]
        private static extern IntPtr MainEngine_getEngine(IntPtr engine);

        [DllImport("libengine.so")]
        private static extern IntPtr MainEngine_getBrake(IntPtr engine);

        [DllImport("libengine.so")]
        private static extern IntPtr MainEngine_getLongitudinalForceModel(IntPtr engine);
    }
}
