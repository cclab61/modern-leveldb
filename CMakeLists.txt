cmake_minimum_required(VERSION 3.0)
project(modern-leveldb VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)

# 查找所有的子目录
file(GLOB DIRS LIST_DIRECTORIES true ${CMAKE_SOURCE_DIR}/third_party/*)
foreach(subdir ${DIRS})
    if(IS_DIRECTORY ${subdir} AND EXISTS ${subdir}/CMakeLists.txt)
        message("add dir: ${subdir}")
        # 添加某个目录的include
        include_directories(${subdir}/include)
        # 作为subdir
        add_subdirectory(${subdir})
    endif()
endforeach()

add_executable(test_main src/test_main.cc)

target_link_libraries(test_main gtest gtest_main co)