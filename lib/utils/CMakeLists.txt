add_library(logger logger.hpp logger.cpp)

target_link_libraries(logger PRIVATE spdlog)

target_include_directories(logger PUBLIC ${PROJECT_SOURCE_DIR})
