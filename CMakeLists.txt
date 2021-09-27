cmake_minimum_required(VERSION 3.2)
project(my_engine)
set(CMAKE_CXX_STANDARD 17)
set(SOURCES_PATH ${CMAKE_SOURCE_DIR}/source)
set( HEADERS
	${SOURCES_PATH}/magicBox.h
	${SOURCES_PATH}/object.h
	${SOURCES_PATH}/character.h
	${SOURCES_PATH}/icons.h
	${SOURCES_PATH}/mapGeneric.h
	${SOURCES_PATH}/button.h
	${SOURCES_PATH}/buttonManager.h
)
set (SOURCES 
	${SOURCES_PATH}/main.cpp
	${SOURCES_PATH}/object.cpp
	${SOURCES_PATH}/character.cpp
	${SOURCES_PATH}/icons.cpp
	${SOURCES_PATH}/mapGeneric.cpp
	${SOURCES_PATH}/button.cpp
	${SOURCES_PATH}/buttonManager.cpp
)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(my_engine PRIVATE sfml-system sfml-network sfml-graphics sfml-window)