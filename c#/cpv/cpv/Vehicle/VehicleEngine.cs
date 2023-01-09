using System;
using System.Runtime.InteropServices;
using static cpv.Common.Common;

namespace cpv
{
    public class VehicleEngine
    {
        public VehicleEngine()
        {
            instance = Engine_new();
        }

        public VehicleEngine(IntPtr instance, bool managed = false) {
            this.instance = instance;
            this.managed = managed;
        }

        ~VehicleEngine()
        {
            Engine_delete(instance);
        }

        public int IdleRpm
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

        public int MaxRpm
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

        public int Rpm
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

        public double Throttle
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

        private readonly IntPtr instance;
        private readonly bool managed;

        [DllImport(DllName)]
        private static extern IntPtr Engine_new();

        [DllImport(DllName)]
        private static extern void Engine_delete(IntPtr engine);

        [DllImport(DllName)]
        private static extern void Engine_setIdleRpm(IntPtr engine, int idleRpm);

        [DllImport(DllName)]
        private static extern int Engine_getIdleRpm(IntPtr engine);

        [DllImport(DllName)]
        private static extern void Engine_setMaxRpm(IntPtr engine, int maxRpm);

        [DllImport(DllName)]
        private static extern int Engine_getMaxRpm(IntPtr engine);

        [DllImport(DllName)]
        private static extern void Engine_setRpm(IntPtr engine, int rpm);

        [DllImport(DllName)]
        private static extern int Engine_getRpm(IntPtr engine);

        [DllImport(DllName)]
        private static extern void Engine_setThrottle(IntPtr engine, double throttle);

        [DllImport(DllName)]
        private static extern double Engine_getThrottle(IntPtr engine);

    }
}
