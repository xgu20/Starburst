cmake_minimum_required(VERSION 3.5)
project(starburst)

find_package(OpenCV REQUIRED)

# add_executable(test test.cpp)

add_executable(cvEyeTracker cvEyeTracker.cpp)
target_link_libraries(cvEyeTracker ${OpenCV_LIBS})