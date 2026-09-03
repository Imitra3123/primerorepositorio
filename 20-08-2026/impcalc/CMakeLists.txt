cmake_minimum_required(VERSION 3.20)
project(impCalc CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        impcalC.cpp
        Operations/add.cpp
        Operations/divide.cpp
        Operations/multiply.cpp
        Operations/subtract.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "C:/raylib/raylib/src"
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/clay
        ${CMAKE_CURRENT_SOURCE_DIR}/Operations
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        "C:/raylib/raylib/src/libraylib.a"
        Winmm
        gdi32
        opengl32
)
