maininc = include_directories('../include')

mainlib = static_library('engineImpl', 'MainEngine.cpp', include_directories: [maininc, coreinc, vehicleinc], link_with: [corelib, brakelib, enginelib, longforcelib], dependencies: [rapidjson_dep])

maininterface = shared_library('engine', 
                              ['MainEngineInterface.cpp', 'EngineInterface.cpp', 'BrakeInterface.cpp'], 
                              include_directories: [maininc, coreinc, vehicleinc], 
                              link_with: [corelib, brakelib, enginelib, longforcelib, mainlib], 
                              dependencies: [rapidjson_dep], 
                              install: true,
                              install_dir: '/usr/lib')