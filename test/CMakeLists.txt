if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif()

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/test")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/test")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/test")

add_executable(${WS_TEST_NAME}
               t_methoddescrciption.cpp
               main.cpp)

# speed up compilation
#target_precompile_headers(${CMAKE_PROJECT_NAME} PRIVATE
#                          ${CMAKE_CURRENT_SOURCE_DIR}/webservice.h)

target_link_libraries(${WS_TEST_NAME}
                      ${WS_LIB_NAME}
                      gtest)