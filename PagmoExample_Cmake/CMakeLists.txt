# CMakeList.txt : CMake project for PagmoExample_Cmake, include source and define
# project specific logic here.
#

# Look for an installation of pagmo in the system.
find_package(Pagmo REQUIRED)

# Add source to this project's executable.
add_executable (PagmoExample_Cmake "PagmoExample_Cmake.cpp" "PagmoExample_Cmake.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PagmoExample_Cmake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_link_libraries(PagmoExample_Cmake Pagmo::pagmo)