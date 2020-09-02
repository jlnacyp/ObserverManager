cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE Release)

project(Pratice_Obsever)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/src/observermanager
)

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
pthread
)
