#pragma once

#include <spdlog/spdlog.h>

namespace rvx {

class Logger {
public:
     static void init(const std::string& level = "info");
};

} // namespace rvx
