maininc = include_directories('../include')

mainlib = shared_library('engine', 'MainEngine.cpp', include_directories: [maininc, coreinc, vehicleinc], link_with: [corelib, brakelib, enginelib, longforcelib], dependencies: [rapidjson_dep], install:true)