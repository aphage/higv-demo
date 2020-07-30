set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_HOST_SYSTEM_PROCESSOR arm)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

set(CMAKE_C_FLAGS "-mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4")
set(CMAKE_CXX_FLAGS "-mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4")
set(CMAKE_C_FLAGS_DEBUG "-Wall -g -ggdb3 -O0 ")
set(CMAKE_C_FLAGS_RELEASE "-Wall -O3")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -ggdb3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O3")
