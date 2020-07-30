project(xml-demo)

add_executable(${PROJECT_NAME}
src/main.cpp
)

install_targets(${PROJECT_NAME} TARGETS ${CMAKE_SOURCE_DIR}/bin)
install_targets(${PROJECT_NAME} DIRECTORY ${CMAKE_SOURCE_DIR}/resource DESTINATION ${CMAKE_SOURCE_DIR}/bin)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
mkdir ${PROJECT_SOURCE_DIR}/resource && mkdir ${PROJECT_SOURCE_DIR}/resource/languages
COMMAND ${CMAKE_SOURCE_DIR}/lib/higv/tools/64bit_xml2bin/xml2bin -b ${PROJECT_SOURCE_DIR}/resource/app.bin \
-e ${PROJECT_SOURCE_DIR}/ -t c -l ${PROJECT_SOURCE_DIR}/resource/languages -x ${PROJECT_SOURCE_DIR}/xml
COMMAND cp -f ${PROJECT_SOURCE_DIR}/resource/higv_cextfile.c ${PROJECT_SOURCE_DIR}/src/
COMMAND cp -f ${PROJECT_SOURCE_DIR}/resource/higv_cextfile.h ${PROJECT_SOURCE_DIR}/src/
COMMAND cp -f ${PROJECT_SOURCE_DIR}/resource/higv_language.h ${PROJECT_SOURCE_DIR}/src/
COMMAND cp ${PROJECT_SOURCE_DIR}/resource/app.bin ${CMAKE_SOURCE_DIR}/resource
COMMAND cp ${PROJECT_SOURCE_DIR}/resource/languages ${CMAKE_SOURCE_DIR}/resource
COMMAND rm -rf ${PROJECT_SOURCE_DIR}/resource
)

target_link_libraries(${PROJECT_NAME}
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
