cmake_minimum_required(VERSION 3.0.0)
project(Exercize01 VERSION 0.1.0)

add_library(Exercize01 SHARED anomaly_detection_util.cpp MainTrain.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
