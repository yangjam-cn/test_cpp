/**
 * @author yangjian 1171267147@qq.com
 * @brief 测试框架，使用随机颜色填充窗口
 * @version 0.1
 * @date 2023-04-05
 *
 * @copyright Copyright (c) 2023
 */
#include <random>
#include <ctime>

#include "sdl_framework.hpp"

class CCase04 : public CSdlFrameworkBase {
public:
    CCase04()  = default;
    ~CCase04() = default;

    void RenderWindow() override
    {
        SDL_RenderClear(m_pRenderer);

        int r = std::rand() % 255;
        int g = std::rand() % 255;
        int b = std::rand() % 255;
        spdlog::info("r:{}, g:{}, b:{}", r, g, b);
        SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 0);

        SDL_RenderPresent(m_pRenderer);
    }
};

int main()
{
    srand(time(nullptr));

    CCase04 case04;

    if (case04.Init("rand color") != 0)
    {
        spdlog::error("Failed to initialize case04");
        return -1;
    }

    int i = 0;
    do
    {
        case04.RenderWindow();
        SDL_Delay(1000);
        i++;
    } while (i < 10);

    return 0;
}