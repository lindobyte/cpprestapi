if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif()

add_library(${WS_LIB_NAME}
            ${CMAKE_CURRENT_SOURCE_DIR}/resource/country/Country.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/resource/customer/Customer.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/resource/MethodDescription.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/resource/Resource.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/resource/ResourceFactory.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Const.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Webservice.cpp)

# speed up compilation
#target_precompile_headers(${WS_LIB_NAME} PRIVATE
#                          ${CMAKE_CURRENT_SOURCE_DIR}/Webservice.hpp
#                          ${CMAKE_CURRENT_SOURCE_DIR}/resource/Resource.hpp)

target_link_libraries(${WS_LIB_NAME}
                      cpprest
                      ssl
                      crypto)

add_subdirectory(app)