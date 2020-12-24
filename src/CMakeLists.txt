if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif()



add_executable(${CMAKE_PROJECT_NAME}
               ${CMAKE_CURRENT_SOURCE_DIR}/resource/customer/Customer.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/resource/AbstractResource.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/resource/MethodDescription.cpp
               main.cpp)

# speed up compilation
target_precompile_headers(${CMAKE_PROJECT_NAME} PRIVATE
                          ${CMAKE_CURRENT_SOURCE_DIR}/webservice.h)

target_link_libraries(${CMAKE_PROJECT_NAME}
                      cpprest
                      ssl
                      crypto)