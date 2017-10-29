project(MAKE_INDEX)

# add_library(main main.c)

add_executable(make_index make_index.c)

target_link_libraries(make_index pthread)