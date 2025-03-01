cmake_minimum_required(VERSION 3.25.0)
project(SDLTest VERSION 0.1.0 LANGUAGES C)
#set(CMAKE_C_STANDARD 98)
#set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow)
endif()

# Add the executable target
add_executable(SDLTest main.c)

# Link SDL2
set(SDL2_INCLUDE_DIR "d:/msys64/mingw64/include/SDL2")
set(SDL2_LIBRARY "d:/msys64/mingw64/lib/libSDL2.dll.a")
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(SDLTest PRIVATE ${SDL2_LIBRARY})
target_include_directories(SDLTest PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(SDLTest PRIVATE ${SDL2_LIBRARIES})