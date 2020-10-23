add_library(Duplicates duplicates.cxx)
include_directories("${PROJECT_SOURCE_DIR}/Feats")
target_link_libraries(Duplicates PUBLIC Feats)
