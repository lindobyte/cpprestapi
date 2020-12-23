cmake_minimum_required(VERSION 3.5)
project(webservice VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

link_directories(/usr/local/lib)
link_directories(/usr/local/opt/openssl/lib)

include_directories(/usr/local/include
                    /usr/local/opt/openssl/include)

add_subdirectory(src)