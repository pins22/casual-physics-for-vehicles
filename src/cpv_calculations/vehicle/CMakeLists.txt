add_library(vehicle STATIC src/Engine.cpp)

target_include_directories(vehicle PUBLIC include)
target_include_directories(vehicle PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                     $<INSTALL_INTERFACE:include/>)
target_link_libraries(vehicle PUBLIC core)

get_target_property(CORE_SRCS core INTERFACE_SOURCES)
source_group("Header Files\\core" FILES ${WINDOW_SRCS})


if(ENABLE_TESTS)
    add_subdirectory(test)
endif()