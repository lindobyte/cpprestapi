cmake_minimum_required(VERSION 3.5)
project(webservice VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

link_directories(/usr/local/lib)
link_directories(/usr/local/opt/openssl/lib)

include_directories(/usr/local/include
                    /usr/local/opt/openssl/include)

set(WS_LIB_NAME  ${CMAKE_PROJECT_NAME})
set(WS_EXE_NAME  "${CMAKE_PROJECT_NAME}_httpd")
set(WS_TEST_NAME "t_${CMAKE_PROJECT_NAME}")

add_subdirectory(src)
add_subdirectory(test)