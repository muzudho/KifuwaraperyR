#include "muz_default_logger_model.hpp"


void MuzDefaultLoggerModel::trace(const std::string& message) const
{
    try
    {
        spdlog::trace(message.c_str());
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "spdlog failed: " << ex.what() << std::endl;
    }
}


void MuzDefaultLoggerModel::debug(const std::string& message) const
{
    try
    {
        spdlog::debug(message.c_str());
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "spdlog failed: " << ex.what() << std::endl;
    }
}


void MuzDefaultLoggerModel::info(const std::string& message) const
{
    try
    {
        spdlog::info(message.c_str());
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "spdlog failed: " << ex.what() << std::endl;
    }
}


void MuzDefaultLoggerModel::warn(const std::string& message) const
{
    try
    {
        spdlog::warn(message.c_str());
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "spdlog failed: " << ex.what() << std::endl;
    }
}


void MuzDefaultLoggerModel::error(const std::string& message) const
{
    try
    {
        spdlog::error(message.c_str());
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "spdlog failed: " << ex.what() << std::endl;
    }
}


void MuzDefaultLoggerModel::fatal(const std::string& message) const
{
    try
    {
        spdlog::critical(message.c_str());
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "spdlog failed: " << ex.what() << std::endl;
    }
}
