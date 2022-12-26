vehicleinc = include_directories('../include')


brakelib = static_library('brake', 'Brake.cpp', include_directories: vehicleinc)
enginelib = static_library('engine', 'Engine.cpp', include_directories: [vehicleinc, coreinc], link_with: corelib)
longforcelib = static_library('longforce', 'LongitudinalForceModel.cpp', include_directories: inc)