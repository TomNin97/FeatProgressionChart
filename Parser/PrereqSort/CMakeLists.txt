add_library(PrereqSort sort.cxx)
include_directories("${PROJECT_SOURCE_DIR}/Feats"
                    )
target_link_libraries(PrereqSort PUBLIC 
                      "Feats"
                      )
