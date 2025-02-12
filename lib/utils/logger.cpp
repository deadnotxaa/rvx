#include "logger.hpp"

#include <filesystem>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

void rvx::Logger::init(const std::string& level) {
    // Ensure the logs directory exists
    if (!std::filesystem::exists("logs")) {
        std::filesystem::create_directory("logs");
    }

    // Generate a unique log filename based on the current timestamp
    const auto now = std::chrono::system_clock::now();
    const auto time_t_now = std::chrono::system_clock::to_time_t(now);
    const std::tm tm_now = *std::localtime(&time_t_now);

    std::ostringstream filename;
    filename << "logs/rvx_"
             << std::put_time(&tm_now, "%Y-%m-%d_%H-%M-%S")
             << ".log";

    // Create console and file sinks
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename.str(), true);

    // Create a logger with both sinks
    auto logger = std::make_shared<spdlog::logger>("rvx_logger", spdlog::sinks_init_list{console_sink, file_sink});

    // Set global log level
    spdlog::level::level_enum log_level{};

    if (level == "trace") {
        log_level = spdlog::level::trace;
    } else if (level == "debug") {
        log_level = spdlog::level::debug;
    } else if (level == "warn") {
        log_level = spdlog::level::warn;
    } else if (level == "error") {
        log_level = spdlog::level::err;
    } else if (level == "critical") {
        log_level = spdlog::level::critical;
    } else {
        log_level = spdlog::level::info;
    }

    logger->set_level(log_level);
    logger->flush_on(spdlog::level::trace);  // Flush immediately for debugging

    // Set format: [timestamp] [log level] message
    logger->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");

    // Register logger globally
    spdlog::set_default_logger(logger);
}
