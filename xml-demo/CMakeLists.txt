project(xml-demo)

add_executable(xml-demo
src/main.cpp
)

target_link_libraries(xml-demo
    dl
    rt
    m
    pthread
    stdc++
    -rdynamic

    higv.a
    higo.a
    higoadp.a
    tde.a
    freetype.a
    harfbuzz.a
    jpeg.a
    png.a
    securec.a
    z.a

    mpi.a
    dnvqe.a
    upvqe.a
    VoiceEngine.a
)
