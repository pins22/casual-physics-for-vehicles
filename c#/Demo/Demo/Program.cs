using System;
using cpv;

namespace Demo
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            MainEngine engine = new MainEngine();

            engine.initialize(@"
                {
  ""mass"": 1300,
  ""vehicleEngine"": {
    ""idleRPM"": 800,
    ""maxRPM"": 8000,
    ""torqueCurve"": [
      {
        ""throttle"": 0.0,
        ""rpm"": [800, 1000, 4000, 8000],
        ""torque"": [-10, -20, -30, -40]
      },
      {
        ""throttle"": 0.5,
        ""rpm"": [800, 1000, 4000, 8000],
        ""torque"": [100, 100, 200, 100]
      },
      {
        ""throttle"": 1.0,
        ""rpm"": [800, 1000, 4000, 8000],
        ""torque"": [220, 220, 320, 220]
      }
    ]
  },
  ""transmission"": {
    ""gearRatios"": [-3.5, 3.5, 2.5, 1.8, 1.3, 1, 0.8],
    ""finalDriveRatio"": 3.5
  },
  ""brakes"": {
    ""type"": ""simple"",
    ""frontBrake"": {
      ""maxBrakeTorque"": 1000
    }
  },
  ""resistance"": {
    ""dragCoefficient"": 0.5,
    ""rollingResistanceCoefficient"": 0.01
  }
}
            ");

            engine.vehicleEngine.idleRpm = 100;

            Console.WriteLine(engine.vehicleEngine.maxRpm);
            Console.WriteLine(engine.vehicleEngine.idleRpm);
        }
    }
}
