cmake_minimum_required(VERSION 3.10)

project(FeatChart VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(config.h.in config.h)

add_subdirectory(Feats)
add_subdirectory(CSV)
add_subdirectory(UML)
add_subdirectory(Duplicates)
add_subdirectory(PrereqSort)
add_subdirectory(Input)
add_subdirectory(Output)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Input
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

list(APPEND LIBS "Feats" "UML" "CSV" "Duplicates" "PrereqSort")
list(APPEND LOCATIONS "${PROJECT_SOURCE_DIR}/Feats" "${PROJECT_SOURCE_DIR}/UML" "${PROJECT_SOURCE_DIR}/CSV" "${PROJECT_SOURCE_DIR}/Duplicates" "${PROJECT_SOURCE_DIR}/PrereqSort" "${PROJECT_SOURCE_DIR}/Input" "${PROJECT_SOURCE_DIR}/Output")

add_executable(FeatChart main.cxx)

target_link_libraries(FeatChart PUBLIC ${LIBS})

target_include_directories(FeatChart PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${LOCATIONS}"
                           )
