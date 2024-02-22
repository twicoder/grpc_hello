find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

#
# Protobuf/Grpc source files
#
set(PROTO_FILES
    protos/address.proto
    protos/addressbook.proto
)

#
# Add Library target with protobuf sources
#
add_library(${PROTO_LIB_NAME} ${PROTO_FILES})
target_link_libraries(${PROTO_LIB_NAME}
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)
target_include_directories(${PROTO_LIB_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

#
# Compile protobuf and grpc files in ${LIB_NAME} target to cpp
#
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET ${PROTO_LIB_NAME} LANGUAGE cpp)
protobuf_generate(TARGET ${PROTO_LIB_NAME} LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
