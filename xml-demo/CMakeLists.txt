project(xml-demo)

add_executable(xml-demo
main.cpp
)

target_link_libraries(xml-demo
    dl
    rt
    m
    pthread
    stdc++
    -rdynamic

    higv/libhigv.a
    higv/libhigo.a
    higv/libhigoadp.a
    higv/libtde.a
    higv/libfreetype.a
    higv/libharfbuzz.a
    higv/libjpeg.a
    higv/libpng.a
    higv/libsecurec.a
    higv/libz.a

    mpp/libmpi.a
    mpp/libdnvqe.a
    mpp/libupvqe.a
    mpp/libVoiceEngine.a
)

message(STATUS "PROJECT_NAME : ${PROJECT_NAME}")
message(STATUS "CMAKE_C_FLAGS : ${CMAKE_C_FLAGS}")