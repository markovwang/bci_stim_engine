project(modern-cpp-kafka-api)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})

#---------------------------
# librdkafka
#---------------------------
find_package(RdKafka)
# set(LIBRDKAFKA_INCLUDE_DIR "C:\\Program Files\\librdkafka_x64-windows\\include")
# set(LIBRDKAFKA_LIBRARY_DIR "C:\\Program Files\\librdkafka_x64-windows\\share\\RdKafka")
MESSAGE(STATUS ${LIBRDKAFKA_LIBRARY_DIR})
target_include_directories(${PROJECT_NAME} SYSTEM INTERFACE ${LIBRDKAFKA_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} INTERFACE ${LIBRDKAFKA_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} INTERFACE RdKafka::rdkafka)

#---------------------------
# pthread
#---------------------------
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} INTERFACE pthread)
endif ()

#---------------------------
# sasl (if required)
#---------------------------
if (SASL_LIBRARY)
    target_link_directories(${PROJECT_NAME} INTERFACE ${SASL_LIBRARYDIR})
    target_link_libraries(${PROJECT_NAME} INTERFACE ${SASL_LIBRARY})
endif ()

# Header-only
install(DIRECTORY kafka DESTINATION include)
