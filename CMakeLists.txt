cmake_minimum_required(VERSION 3.5)

include(arm-linux.cmake)

project(higv-demo
    VERSION "0.0.1"
    DESCRIPTION "This is a demo"
    HOMEPAGE_URL "https://github.com/aphage/higv-demo"
    LANGUAGES "C CXX")

include_directories(lib)

add_subdirectory(api-demo)
add_subdirectory(xml-demo)

