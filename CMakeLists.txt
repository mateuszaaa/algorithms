cmake_minimum_required(VERSION 3.0)
project(algorithms)

SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Werror")
find_package( OpenCV REQUIRED )

add_executable(app src/main.cpp ./src/ui_opencv.cpp ./src/prim.cpp)
target_link_libraries(app
  ${OpenCV_LIBS}
)

