#include <iostream>

#include "CLI/CLI.hpp"

#include "lib/utils/logger.hpp"

int main(const int argc, char** argv) {
    CLI::App app{"RVX Emulator"};

    std::string log_level = "info";
    app.add_option("--log-level", log_level, "Set log level (trace, debug, info, warn, error, critical)");

    CLI11_PARSE(app, argc, argv);

    rvx::Logger::init(log_level);

    return 0;
}
