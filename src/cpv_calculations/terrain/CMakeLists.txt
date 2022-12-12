add_library(terrain STATIC
    src/terrain.cpp
)

target_include_directories(terrain PRIVATE include)

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
