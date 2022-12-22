cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_EXTENSIONS OFF)

project(
  CalcLib 
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL "%%url%%"
  LANGUAGES CXX C)

enable_testing()

add_subdirectory(core)
add_subdirectory(physics)
add_subdirectory(terrain)
# add_subdirectory(vehicle)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
