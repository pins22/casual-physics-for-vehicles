add_library(core STATIC
    src/core.cpp
)

target_include_directories(core PRIVATE include)

if (ENABLE_TESTS)
    add_subdirectory(test)
endif()
