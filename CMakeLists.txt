cmake_minimum_required(VERSION 3.15)
project(AUTOSE_KMS_20203327)

set(CMAKE_TOOLCHAIN_FILE "/home/kong/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 소스 파일 및 헤더 파일 지정
set(SOURCES
    main.cpp
    sensor.cpp
    kalman_filter.cpp
    collision_checker.cpp
)

set(HEADERS
    sensor.h
    kalman_filter.h
    collision_checker.h
)

add_executable(AUTOSE_KMS_20203327 ${SOURCES} ${HEADERS})

find_package(Eigen3 REQUIRED)

target_link_libraries(AUTOSE_KMS_20203327 Eigen3::Eigen)

target_compile_options(AUTOSE_KMS_20203327 PRIVATE -Wall -Wextra -Werror)
