include_directories(${PROJECT_SOURCE_DIR}/thirdparty/tinyxml)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/tinyxml)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/murpc)

aux_source_directory(. SRC_LIST)

add_library(murpc ${SRC_LIST})
target_link_libraries(murpc muduo_net muduo_base protobuf zookeeper_mt tinyxml pthread)
