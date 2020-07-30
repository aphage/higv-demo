cmake_minimum_required(VERSION 3.12)

include(arm-linux.cmake)

project(higv-demo)

include_directories(lib/higv/include lib/mpp/include)
link_directories(lib/higv/lib lib/mpp/lib)

add_subdirectory(api-demo)
add_subdirectory(xml-demo)

