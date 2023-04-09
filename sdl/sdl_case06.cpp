/**
 * @author yangjian 1171267147@qq.com
 * @brief 事件驱动编程
 * @version 0.1
 * @date 2023-04-05
 *
 * @copyright Copyright (c) 2023
 */

#include "sdl_framework.hpp"

class CCase06 : public CSdlFrameworkBase {
public:
    CCase06()  = default;
    ~CCase06() = default;

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
    CCase06 case06;

    if (case06.Init("texture render") != 0)
    {
        spdlog::error("Failed to initialize case04");
        return -1;
    }

    SDL_Event event;
    bool      quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    spdlog::info("sdl_quit");
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    spdlog::info("sdl_keydown");
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    spdlog::info("sdl_mousebuttondown");
                    break;
                default:
                    break;
            }
        }

        case06.RenderWindow();

        SDL_Delay(1000);
    }

    return 0;
}