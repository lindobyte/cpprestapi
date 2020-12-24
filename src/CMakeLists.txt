if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

add_library(${WS_LIB_NAME}
            ${CMAKE_CURRENT_SOURCE_DIR}/resource/customer/Customer.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/resource/AbstractResource.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/resource/MethodDescription.cpp)

# speed up compilation
target_precompile_headers(${WS_LIB_NAME} PRIVATE
                          ${CMAKE_CURRENT_SOURCE_DIR}/webservice.h)

target_link_libraries(${WS_LIB_NAME}
                      cpprest
                      ssl
                      crypto)

#set_target_properties(${WS_LIB_NAME}
#    PROPERTIES
#    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
#    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
#    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
#)

add_subdirectory(app)