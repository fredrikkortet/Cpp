cmake_minimum_required(VERSION 3.19)
Project( main )
# include OpenCV
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( main basics.cpp )
target_link_libraries( main ${OpenCV_LIBS} )
