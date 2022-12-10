add_library(physics STATIC
    src/physics.cpp
)

target_include_directories(physics PRIVATE include)

if (ENABLE_TESTS)
    add_subdirectory(test)
endif()
