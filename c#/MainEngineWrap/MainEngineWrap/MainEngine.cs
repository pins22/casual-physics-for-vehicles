using System;
using System.Runtime.InteropServices;

namespace MainEngineWrap
{


    public class MainEngine
    {
        public MainEngine()
        {
            instance = MainEngine_new();
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

        private IntPtr instance;

        [DllImport("libengine.so")]
        private static extern IntPtr MainEngine_new();

        [DllImport("libengine.so")]
        private static extern void MainEngine_delete(IntPtr engine);

        [DllImport("libengine.so")]
        private static extern void MainEngine_initialize(IntPtr engine, String str);
    }
}
