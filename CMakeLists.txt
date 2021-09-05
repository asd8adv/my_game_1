cmake_minimum_required(VERSION 3.2)
project(my_engine)
set(CMAKE_CXX_STANDARD 17)
include(F:/vcpkg/scripts/buildsystems/vcpkg.cmake) 

set(SOURCES_PATH ${CMAKE_SOURCE_DIR}/source)
set( HEADERS
	${SOURCES_PATH}/character.h
	${SOURCES_PATH}/icons.h
	${SOURCES_PATH}/magicBox.h
	${SOURCES_PATH}/mapGeneric.h
)
set (SOURCES 
	${SOURCES_PATH}/main.cpp
	${SOURCES_PATH}/character.cpp
	${SOURCES_PATH}/icons.cpp
	${SOURCES_PATH}/mapGeneric.cpp
)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(my_engine PRIVATE sfml-system sfml-network sfml-graphics sfml-window)