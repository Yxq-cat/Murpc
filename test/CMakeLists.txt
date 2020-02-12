set(CLIENT_SRC ./testrpcclient.cpp ./service.pb.cc)
set(SERVER_SRC ./testrpcserver.cpp ./service.pb.cc) 

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/murpc)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(rpc_server ${SERVER_SRC})
target_link_libraries(rpc_server murpc)
add_executable(rpc_client ${CLIENT_SRC})
target_link_libraries(rpc_client murpc)
