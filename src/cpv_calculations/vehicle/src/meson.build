vehicleinc = include_directories('../include')


brakelib = static_library('brake', 'Brake.cpp', include_directories: vehicleinc)
enginelib = static_library('engine', 'Engine.cpp', include_directories: [vehicleinc, coreinc], link_with: corelib)
transmissionlib = static_library('transmission', 'Transmission.cpp', include_directories: [inc, vehicleinc])
longforcelib = static_library('longforce', 'LongitudinalForceModel.cpp', include_directories: [inc, vehicleinc])
latforcelib = static_library('latforce', 'LateralForceModel.cpp', include_directories: [inc, vehicleinc])
corneringlib = static_library('cornering', 'cornering.cpp', include_directories: [inc, vehicleinc, coreinc], link_with: corelib)