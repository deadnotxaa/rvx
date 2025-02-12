include(FetchContent)

# Async logger
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.12.0
)

# CLI arguments parser
FetchContent_Declare(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.3.2
)

# ncurses
find_package(Curses)

if (NOT CURSES_FOUND)
    message(STATUS "ncurses not found in the system, fetching it...")
    FetchContent_Declare(
            ncurses
            GIT_REPOSITORY https://github.com/mirror/ncurses.git
            GIT_TAG master
    )
    FetchContent_MakeAvailable(ncurses)
else()
    message(STATUS "Using system ncurses")
endif()

FetchContent_MakeAvailable(spdlog CLI11)
