cmake_minimum_required(VERSION 3.16)
project(MouseConfigurator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)
find_package(TGUI REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(HIDAPI REQUIRED hidapi-hidraw)

add_executable(mouse_config
    src/main.cpp
)

target_include_directories(mouse_config PRIVATE include ${HIDAPI_INCLUDE_DIRS})
target_link_libraries(mouse_config sfml-graphics sfml-window sfml-system tgui ${HIDAPI_LIBRARIES})
