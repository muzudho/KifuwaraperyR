#pragma once
#include <spdlog/spdlog.h>


bool logging_setup(const std::string& config_path = "config.toml");
void logging_shutdown();
