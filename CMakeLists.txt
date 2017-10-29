project(MAKE_INDEX)

add_executable(make_index make_index.c)

add_executable(indexed_search indexed_search.c)

target_link_libraries(make_index pthread)