# 1 cmake version
cmake_minimum_required(VERSION 3.5)
# 2 the project name, can be anything
project(testjni)
#  set environment variable
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# 3 include path
include_directories(
        #/opt/program/jdk1.8.0_121/include/linux
        #/opt/program/jdk1.8.0_121/include
        /usr/lib/jvm/java-1.8.0-openjdk-amd64/include/linux
        /usr/lib/jvm/java-1.8.0-openjdk-amd64/include

)
# 4 link library path
link_directories(
        #/opt/program/jdk1.8.0_121/jre/lib/amd64/server
        /usr/lib/jvm/java-1.8.0-openjdk-amd64/jre/lib/amd64/server/
)
# 5 add all src files
set(SOURCE_FILES testjni.cpp)
# 6 the output bin name
add_executable(testjni ${SOURCE_FILES})
# 7 add link library, ex(lib+name+.so), only 'name' here
target_link_libraries(
        testjni
        jvm
        )
