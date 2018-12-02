#cmake verson
cmake_minimum_required(VERSION 3.2)

#project name
PROJECT(U201614898_2)

#head file path
INCLUDE_DIRECTORIES(include)

#source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

SET(src_total ${DIR_SRCS} )

#add executable file，
ADD_EXECUTABLE(${PROJECT_NAME} ${src_total})

