add_executable(${WS_EXE_NAME}
               ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(${WS_EXE_NAME}
                      ${WS_LIB_NAME})

#set_target_properties(${WS_EXE_NAME}
#    PROPERTIES
#    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
#    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
#    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
#)