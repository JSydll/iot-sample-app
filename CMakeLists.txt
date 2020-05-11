cmake_minimum_required(VERSION 3.5)
project(iot-sample-app)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME}_lib 
    src/FieldbusSimulator.cpp
    src/DataLogger.cpp
)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} 
    ${PROJECT_NAME}_lib
)