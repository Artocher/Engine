cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/windows/mainwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/windows/openglwindow
    ${CMAKE_CURRENT_SOURCE_DIR}/structures/ 
    ${CMAKE_CURRENT_SOURCE_DIR}/docks/
    ${CMAKE_CURRENT_SOURCE_DIR}/parsers/obj/
    ${CMAKE_CURRENT_SOURCE_DIR}/shaders/
    ${CMAKE_CURRENT_SOURCE_DIR}/shaderprograms/
    ${CMAKE_CURRENT_SOURCE_DIR}/object/
    ${CMAKE_CURRENT_SOURCE_DIR}/mesh/
    ${CMAKE_CURRENT_SOURCE_DIR}/engines/
    ${CMAKE_CURRENT_SOURCE_DIR}/camera/
    ${CMAKE_CURRENT_SOURCE_DIR}/texture/
    ${CMAKE_CURRENT_SOURCE_DIR}/model/
    ${CMAKE_CURRENT_SOURCE_DIR}/menubar/

)

target_sources(${CMAKE_PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/windows/mainwindow/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/windows/openglwindow/openglwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/windows/openglwindow/mainopenglwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/windows/openglwindow/modeldisplaywidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/docks/filedock.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/parsers/obj/object_file_parser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/shaderprograms/shaderprogram.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/shaderprograms/baseshaderprogram.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/object/object.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mesh/mesh.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/engines/engine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/engines/mainengine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/engines/modeldisplayengine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/camera/camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/texture/texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model/model.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/menubar/menubar.cpp
)
