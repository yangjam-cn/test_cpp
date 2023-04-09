/**
 * @author yangjian 1171267147@qq.com
 * @brief 使用宏重新封装spdlog，简化和统一接口
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 */
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>

#define LOG_INIT() spdlog::set_pattern("[%@,%!][%l] %v");
#define LOG_TRACE(...) SPDLOG_LOGGER_TRACE(spdlog::default_logger(), __VA_ARGS__);
#define LOG_DEBUG(...) SPDLOG_LOGGER_DEBUG(spdlog::default_logger(), __VA_ARGS__);
#define LOG_INFO(...) SPDLOG_LOGGER_INFO(spdlog::default_logger(), __VA_ARGS__);
#define LOG_WARN(...) SPDLOG_LOGGER_WARN(spdlog::default_logger(), __VA_ARGS__);
#define LOG_ERROR(...) SPDLOG_LOGGER_ERROR(spdlog::default_logger(), __VA_ARGS__);
