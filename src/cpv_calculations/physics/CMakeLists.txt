add_library(physics STATIC
    src/physics.cpp
)

target_include_directories(physics PRIVATE include)

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
