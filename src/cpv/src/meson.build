maininc = include_directories('../include')

mainlib = library('engine', 'MainEngine.cpp', include_directories: [maininc, coreinc, vehicleinc], link_with: [corelib, brakelib, enginelib, longforcelib], dependencies: [rapidjson_dep])