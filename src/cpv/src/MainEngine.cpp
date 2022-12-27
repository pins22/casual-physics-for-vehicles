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
        

    }
}