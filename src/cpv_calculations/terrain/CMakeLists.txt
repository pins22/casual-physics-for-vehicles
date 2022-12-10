add_library(terrain STATIC
    src/terrain.cpp
)

target_include_directories(terrain PRIVATE include)

if (ENABLE_TESTS)
    add_subdirectory(test)
endif()
