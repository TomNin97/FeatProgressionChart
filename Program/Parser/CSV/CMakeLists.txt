add_library(CSV csv.cxx)
include_directories("${PROJECT_SOURCE_DIR}/Feats")
target_link_libraries(CSV PUBLIC Feats)
