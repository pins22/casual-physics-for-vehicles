#include <MainEngine.h>
#include <iostream> 

namespace cpv
{
    MainEngine::MainEngine()
    {
    }

    void MainEngine::initializeVehicle(const std::string& vehicleParametersJson)
    {
        initializeVehicle(vehicleParametersJson.c_str());
    }

    void MainEngine::initializeVehicle(const char* vehicleParametersJson)
    {
        rapidjson::Document document;
        document.Parse(vehicleParametersJson);
        if (document.HasParseError())
        {
            std::cout << "Error parsing JSON" << std::endl;
            return;
        }
        if (document.HasMember("engine"))
        {
            const rapidjson::Value& engine = document["engine"];
            if (engine.HasMember("maxTorque"))
            {
                const rapidjson::Value& maxTorque = engine["maxTorque"];
                if (maxTorque.IsDouble())
                {
                    std::cout << "Max torque: " << maxTorque.GetDouble() << std::endl;
                }
            }
        }
    }
}