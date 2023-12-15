cmake_minimum_required(VERSION 3.0)
project(memes-bot)
set(SOURCE main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


find_package(cpr REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
include_directories(/usr/local/include/tgbot  ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR} json/include header/)
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()

add_library(Mainloop STATIC src/Mainloop.cpp)
add_library(Post STATIC src/Post.cpp)
add_library(TgAPI STATIC src/TgAPI.cpp)
add_library(VKAPI STATIC src/VKAPI.cpp)

target_link_libraries(Mainloop VKAPI TgAPI)
target_link_libraries(VKAPI Post  cpr::cpr)
target_link_libraries(TgAPI Post /usr/local/lib/libTgBot.a  ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Mainloop)



