cmake_minimum_required(VERSION 3.26)
project(money_manager)

add_executable(money_manager main.cpp
        cashpro_wrapper.h
        cashpro_wrapper.cpp)

set(CMAKE_CXX_STANDARD 17)

set(CURL_INCLUDE_DIR "C:/curl/include")
set(CURL_LIBRARY_DIR "C:/curl/lib")

include_directories(${CURL_INCLUDE_DIR})

find_library(CURL_LIBRARY NAMES libcurl_imp libcurl PATHS ${CURL_LIBRARY_DIR})
target_link_libraries(money_manager ${CURL_LIBRARY})
