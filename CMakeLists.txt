cmake_minimum_required(VERSION 3.8)
project(Nodo_Terminal)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dispatcher.cpp Dispatcher.h Server.cpp Server.h Mensaje.cpp Mensaje.h Client.cpp Client.h)
find_package(Threads)
add_executable(Nodo_Terminal ${SOURCE_FILES})
target_link_libraries(Nodo_Terminal ${CMAKE_THREAD_LIBS_INIT})