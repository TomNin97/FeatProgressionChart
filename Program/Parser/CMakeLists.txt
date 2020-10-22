cmake_minimum_required(VERSION 3.10)

project(FeatChart VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(config.h.in config.h)

add_subdirectory(Feats)

add_executable(FeatChart main.cxx)

target_link_libraries(FeatChart PUBLIC Feats)

target_include_directories(FeatChart PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Feats"
                           )
