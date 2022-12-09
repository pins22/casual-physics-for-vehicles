cmake_minimum_required(VERSION 3.16)

# Not ideal to use this global variable, but necessary to make sure
# that tooling and projects use the same version
set(CMAKE_CXX_STANDARD 17)

# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

project(
  calc_lib
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL "%%url%%"
  LANGUAGES CXX C)


  add_subdirectory(core)
