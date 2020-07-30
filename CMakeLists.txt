cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Engine VERSION 1.0 LANGUAGES CXX)

# Add gcc colors
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options (-fdiagnostics-color=always)
endif()

find_package(Qt5
    COMPONENTS
        Core      REQUIRED
        Widgets   REQUIRED
        Gui       REQUIRED
)

add_executable(Engine ${CMAKE_SOURCE_DIR}/src/main.cpp)
    
target_link_libraries(Engine PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui)

file(COPY resources/ DESTINATION ./)

set_target_properties(Engine
    PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON

        LINKER_LANGUAGE     CXX
        LINK_WHAT_YOU_USE   TRUE
)

add_subdirectory(src)
