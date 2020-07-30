cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/windows/mainwindow
)

target_sources(${CMAKE_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/windows/mainwindow/mainwindow.cpp
)
