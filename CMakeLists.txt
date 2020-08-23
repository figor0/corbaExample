cmake_minimum_required(VERSION 3.5)

project(corba_sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick Sql REQUIRED)

include_directories(/usr/include/omniORB4 /usr/include/omnithread)

set(OMNIIDLFILES
    object.hh
    objectSK.cc
)
set(HEADERS Servant.h)
set(SOURCES Servant.cpp)

add_executable(server server.cpp ${OMNIIDLFILES} ${HEADERS} ${SOURCES})

target_link_libraries(server
  PRIVATE pthread omniORB4 omnithread
)


add_executable(client client.cpp ${OMNIIDLFILES} ${HEADERS} ${SOURCES})

target_link_libraries(client
  PRIVATE pthread omniORB4 omnithread
)
