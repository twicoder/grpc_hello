#
# Dependencies
#
find_package(Threads)

#
# Sources
#
set(SOURCES
    src/main.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})


#
# Target
#
add_executable(store ${SOURCES})
target_link_libraries(store
    PRIVATE
        ${PROTO_LIB_NAME}
)
