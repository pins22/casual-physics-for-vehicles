maininc = include_directories('../include')

message(host_machine.system())


if host_machine.system() == 'Linux'
    mainlib = static_library('engineImpl', 'MainEngine.cpp', include_directories: [maininc, coreinc, vehicleinc], link_with: [corelib, brakelib, enginelib, longforcelib, transmissionlib], dependencies: [rapidjson_dep])
cpp_sources = ['MainEngineInterface.cpp', 'EngineInterface.cpp', 'BrakeInterface.cpp', 'TransmissionInterface.cpp']
maininterface = shared_library('engine', 
                              cpp_sources, 
                              include_directories: [maininc, coreinc, vehicleinc], 
                              link_with: [corelib, brakelib, enginelib, longforcelib, mainlib, transmissionlib], 
                              dependencies: [rapidjson_dep], 
                              install: true,
                              install_dir: '/usr/lib')
endif
if host_machine.system() == 'windows'
    mainlib = static_library('engineImpl', 'MainEngine.cpp', include_directories: [maininc, coreinc, vehicleinc], link_with: [corelib, brakelib, enginelib, longforcelib, transmissionlib], dependencies: [rapidjson_dep])
cpp_sources = ['MainEngineInterface.cpp', 'EngineInterface.cpp', 'BrakeInterface.cpp', 'TransmissionInterface.cpp']
maininterface = shared_library('engine', 
                              cpp_sources, 
                              include_directories: [maininc, coreinc, vehicleinc], 
                              link_with: [corelib, brakelib, enginelib, longforcelib, mainlib, transmissionlib], 
                              dependencies: [rapidjson_dep], 
                              install: true,
                              install_dir: 'C:/Program Files/CPV')
endif