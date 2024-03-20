cmake_minimum_required(VERSION 3.0.0)
project(Game_of_Life VERSION 0.1.0 LANGUAGES C)


include(CTest)
enable_testing()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
FILE(GLOB MyCSources *.c)


link_directories("${CMAKE_SOURCE_DIR}/CSFML/lib/gcc")
link_directories("${CMAKE_SOURCE_DIR}/src/functions")
include_directories("${CMAKE_SOURCE_DIR}/src/functions")
include_directories("${CMAKE_SOURCE_DIR}/CSFML/include")
link_directories("${CMAKE_SOURCE_DIR}/CSFML/lib")
link_directories("${CMAKE_SOURCE_DIR}/CSFML")

AUX_SOURCE_DIRECTORY(dir VARIABLE)

add_executable(Game_of_Life src/main.c src/functions/functions.c)

target_link_libraries(Game_of_Life csfml-graphics-2 csfml-window-2 csfml-system-2)