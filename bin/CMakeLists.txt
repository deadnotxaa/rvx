add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE logger spdlog CLI11 ${CURSES_LIBRARIES})

# Ensure logs directory exists before running the program
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/logs
)
