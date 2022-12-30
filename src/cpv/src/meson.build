maininc = include_directories('../include')

mainlib = static_library('engineImpl', 'MainEngine.cpp', include_directories: [maininc, coreinc, vehicleinc], link_with: [corelib, brakelib, enginelib, longforcelib, transmissionlib], dependencies: [rapidjson_dep])
cpp_sources = ['MainEngineInterface.cpp', 'EngineInterface.cpp', 'BrakeInterface.cpp', 'TransmissionInterface.cpp']
maininterface = shared_library('engine', 
                              cpp_sources, 
                              include_directories: [maininc, coreinc, vehicleinc], 
                              link_with: [corelib, brakelib, enginelib, longforcelib, mainlib, transmissionlib], 
                              dependencies: [rapidjson_dep], 
                              install: true,
                              install_dir: '/usr/lib')