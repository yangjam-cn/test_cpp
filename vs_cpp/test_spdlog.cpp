/**
 * @author yangjian 1171267147@qq.com
 * @brief 测试spdlog库
 * @version 0.1
 * @date 2023-03-15
 * 
 * @copyright Copyright (c) 2023
 */
#include <spdlog/spdlog.h>

int main(int argc, char** argv)
{
    spdlog::set_level(spdlog::level::debug);

    spdlog::info("Hello spflog!");

    int test_var = 10;
    spdlog::debug("test_var = {}", test_var);

    return 0;
}