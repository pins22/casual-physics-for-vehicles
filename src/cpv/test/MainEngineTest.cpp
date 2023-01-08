#include "gtest/gtest.h"
#include "MainEngine.h"

TEST(MainTests, InitializeFromJson)
{
    cpv::MainEngine mainEngine;

    mainEngine.initializeVehicle(R"""({
  "mass": 1300,
  "vehicleEngine": {
    "idleRPM": 800.0,
    "maxRPM": 8000.0,
    "torqueCurve": [
      {
        "throttle": 0.0,
        "rpm": [800, 1000, 4000, 8000],
        "torque": [-10, -20, -30, -40]
      },
      {
        "throttle": 0.5,
        "rpm": [800, 1000, 4000, 8000],
        "torque": [100, 100, 200, 100]
      },
      {
        "throttle": 1.0,
        "rpm": [800, 1000, 4000, 8000],
        "torque": [220, 220, 320, 220]
      }
    ]
  },
  "transmission": {
    "gearRatios": [-3.5, 3.5, 2.5, 1.8, 1.3, 1, 0.8],
    "finalDriveRatio": 3.5
  },
  "brakes": {
    "type": "simple",
    "frontBrake": {
      "maxBrakeTorque": 1000
    }
  },
  "resistance": {
        "dragCoefficient" : 0.5,
            "rollingResistanceCoefficient" : 0.01
  }
}
)""");
    const auto engine = mainEngine.getEngine();
    ASSERT_DOUBLE_EQ(engine->getMaxRpm(), 8000);
    ASSERT_DOUBLE_EQ(engine->getIdleRpm(), 800);

    // ASSERT_DOUBLE_EQ(engine->getTorqueCurve().getYValue(0, 800), 220);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}