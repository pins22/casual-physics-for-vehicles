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

        if(document.HasMember("vehicleEngine")) {
            const rapidjson::Value& vehicleEngine = document["vehicleEngine"];
            if(vehicleEngine.HasMember("torqueCurve")) {
                const rapidjson::Value& torqueCurve = vehicleEngine["torqueCurve"];
                if(torqueCurve.HasMember("x") && torqueCurve.HasMember("y")) {
                    const rapidjson::Value& x = torqueCurve["x"];
                    const rapidjson::Value& y = torqueCurve["y"];
                    FunctionCurve3 engineTorqueCurve;
                    if(x.IsArray() && y.IsArray() && x.Size() == y.Size()) {
                        for (rapidjson::SizeType i = 0; i < x.Size(); i++) {
                        }
                        engine.setTorqueCurve(engineTorqueCurve);
                    }
                }
            }
        }
        

    }
}