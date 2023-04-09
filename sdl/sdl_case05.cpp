/**
 * @author yangjian 1171267147@qq.com
 * @brief 测试框架，使用随机颜色填充窗口
 * @version 0.1
 * @date 2023-04-05
 *
 * @copyright Copyright (c) 2023
 */

#include "sdl_framework.hpp"

class CCase05 : public CSdlFrameworkBase {
public:
    CCase05()  = default;
    ~CCase05() = default;

    void RenderWindow() override
    {
        auto background = LoadTexture("test.bmp");
        auto front      = LoadTexture("resources/picture/wallpaper19.jpg");

        SDL_RenderClear(m_pRenderer);

        RenderTexture(background, nullptr, nullptr);

        SDL_Rect backRect = {DEFAULT_WIDTH / 4, DEFAULT_HEIGHT / 4, DEFAULT_WIDTH / 2, DEFAULT_HEIGHT / 2};
        // SDL_Rect frontRect = {DEFAULT_WIDTH / 4, DEFAULT_HEIGHT / 4, DEFAULT_WIDTH / 2, DEFAULT_HEIGHT / 2};

        RenderTexture(front, nullptr, &backRect);

        SDL_RenderPresent(m_pRenderer);
    }
};

int main()
{
    CCase05 case05;

    if (case05.Init("texture render") != 0)
    {
        spdlog::error("Failed to initialize case04");
        return -1;
    }

    case05.RenderWindow();

    SDL_Delay(5000);

    return 0;
}