#include <MainEngine.h>
#include <iostream>

namespace cpv
{
    MainEngine::MainEngine()
    {
        engine = std::make_shared<Engine>();
        brake = std::make_shared<Brake>();
        longitudinalForceModel = std::make_shared<LongitudinalForceModel>();
    }

    void MainEngine::initializeVehicle(const std::string &vehicleParametersJson)
    {
        initializeVehicle(vehicleParametersJson.c_str());
    }

    void MainEngine::initializeVehicle(const char *vehicleParametersJson)
    {
        rapidjson::Document document;
        document.Parse(vehicleParametersJson);
        if (document.HasParseError())
        {
            std::cout << "Error parsing JSON" << std::endl;
            return;
        }

        if (document.HasMember("vehicleEngine"))
        {
            const rapidjson::Value &vehicleEngine = document["vehicleEngine"];
            if (vehicleEngine.HasMember("torqueCurve"))
            {
                const rapidjson::Value &torqueCurve = vehicleEngine["torqueCurve"];
                FunctionCurve3 torqueCurveFunction;
                for (rapidjson::SizeType i = 0; i < torqueCurve.Size(); i++)
                {
                    const rapidjson::Value &torqueCurvePoint = torqueCurve[i];
                    if (torqueCurvePoint.HasMember("throttle"))
                    {
                        const rapidjson::Value &throttle = torqueCurvePoint["throttle"];
                        const double throttleValue = throttle.GetDouble();
                        if (torqueCurvePoint.HasMember("rpm") && torqueCurvePoint.HasMember("torque"))
                        {
                            const rapidjson::Value &rpm = torqueCurvePoint["rpm"];
                            const rapidjson::Value &torque = torqueCurvePoint["torque"];
                            if (rpm.IsArray() && torque.IsArray())
                            {
                                FunctionCurve2 rpmtq;
                                for (rapidjson::SizeType j = 0; j < rpm.Size(); j++)
                                {
                                    rpmtq.addPoint(rpm[j].GetDouble(), torque[j].GetDouble());
                                }
                                torqueCurveFunction.addCurveFunction(rpmtq, throttleValue);
                            }
                        }
                    }
                }
                engine->setTorqueCurve(torqueCurveFunction);

            }

            if(vehicleEngine.HasMember("maxRPM"))
            {
                const rapidjson::Value &maxRpm = vehicleEngine["maxRPM"];
                engine->setMaxRpm(maxRpm.GetDouble());
            }

            if(vehicleEngine.HasMember("idleRPM")){
                const rapidjson::Value &idleRpm = vehicleEngine["idleRPM"];
                engine->setIdleRpm(idleRpm.GetDouble());
            }
        }
    }
    std::shared_ptr<Engine> MainEngine::getEngine()
    {
        return engine;
    }
}
