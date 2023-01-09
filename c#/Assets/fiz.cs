using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using cpv;

public class fiz : MonoBehaviour
{
    public Rigidbody mrb;
    public MainEngine mainE = new MainEngine();

    // Start is called before the first frame update
    void Start()
    {
        /*mainE.initialize(@"
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
            }"
        );

        Debug.Log(mainE.vehicleEngine.maxRpm);
        Debug.Log(mainE.vehicleEngine.idleRpm);*/
        //Console.WriteLine(mainE.vehicleEngine.maxRpm);
        //Console.WriteLine(mainE.vehicleEngine.idleRpm);
    }

    // Update is called once per frame
    void Update()
    {
        

        if(Input.GetKeyDown(KeyCode.Space) == true)
            mrb.velocity = Vector3.up * 5;
    }
}
