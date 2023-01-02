using System;
using System.Runtime.InteropServices;

namespace cpv
{
    public class VehicleEngine
    {
        public VehicleEngine()
        {
            instance = IntPtr.Zero;
        }

        public VehicleEngine(IntPtr instance) {
            this.instance = instance;
        }

        public int idleRpm
        {
            get
            {
                return Engine_getIdleRpm(instance);
            }
            set
            {
                Engine_setIdleRpm(instance, value);
            }
        }

        public int maxRpm
        {
            get
            {
                return Engine_getMaxRpm(instance);
            }

            set
            {
                Engine_setMaxRpm(instance, value); 
            }

        }

        public int rpm
        {
            get
            {
                return Engine_getRpm(instance);
            }
            set
            {
                Engine_setRpm(instance, value);
            }
        }

        public double throttle
        {
            get
            {
                return Engine_getThrottle(instance);
            }
            set
            {
                Engine_setThrottle(instance, value);
            }
        }

        private IntPtr instance;

        [DllImport("libengine.dll")]
        private static extern void Engine_setIdleRpm(IntPtr engine, int idleRpm);

        [DllImport("libengine.dll")]
        private static extern int Engine_getIdleRpm(IntPtr engine);

        [DllImport("libengine.dll")]
        private static extern void Engine_setMaxRpm(IntPtr engine, int maxRpm);

        [DllImport("libengine.dll")]
        private static extern int Engine_getMaxRpm(IntPtr engine);

        [DllImport("libengine.dll")]
        private static extern void Engine_setRpm(IntPtr engine, int rpm);

        [DllImport("libengine.dll")]
        private static extern int Engine_getRpm(IntPtr engine);

        [DllImport("libengine.dll")]
        private static extern void Engine_setThrottle(IntPtr engine, double throttle);

        [DllImport("libengine.dll")]
        private static extern double Engine_getThrottle(IntPtr engine);

    }
}
