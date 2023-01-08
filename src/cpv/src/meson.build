maininc = include_directories('../include')

message(host_machine.system())

mainlib = static_library('engineImpl', 'MainEngine.cpp', include_directories: [maininc, coreinc, vehicleinc], link_with: [corelib, brakelib, enginelib, longforcelib, transmissionlib], dependencies: [rapidjson_dep])
cpp_sources = ['MainEngineInterface.cpp', 'EngineInterface.cpp', 'BrakeInterface.cpp', 'TransmissionInterface.cpp', 'Vector2Interface.cpp', 'Vector3Interface.cpp', 'FunctionCurve2Interface.cpp', 'FunctionCurve3Interface.cpp']

if host_machine.system() == 'linux'
maininterface = shared_library('engine', 
                              cpp_sources, 
                              include_directories: [maininc, coreinc, vehicleinc], 
                              link_with: [corelib, brakelib, enginelib, longforcelib, mainlib, transmissionlib], 
                              dependencies: [rapidjson_dep], 
                              install: true,
                              install_dir: '/usr/lib')
endif
if host_machine.system() == 'windows'
maininterface = shared_library('engine', 
                              cpp_sources, 
                              include_directories: [maininc, coreinc, vehicleinc], 
                              link_with: [corelib, brakelib, enginelib, longforcelib, mainlib, transmissionlib], 
                              dependencies: [rapidjson_dep], 
                              install: true,
                              install_dir: 'C:/Program Files/CPV')
endif