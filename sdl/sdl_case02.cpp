/**
 * @author yangjian 1171267147@qq.com
 * @brief SDL创建一个窗口，并用图像渲染窗口
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "usage: " << argv[0] << "jpg image" << std::endl;
        return 0;
    }

    // 1. 初始化SDL2和IMG
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);

    // 2. 创建窗口和渲染器
    SDL_Window* window =
        SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 3. 加载图像并创建纹理
    SDL_Surface* surface= IMG_Load(argv[1]);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // 4. 循环处理事件
    bool      quit = false;
    SDL_Event event;
    while (!quit)
    {
        // 处理事件
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // 用指定颜色渲染窗口
        SDL_SetRenderDrawColor(renderer, 125, 0, 125, 0);
        // 清理渲染器
        SDL_RenderClear(renderer);

        // 用纹理填充指定区域
        SDL_Rect rect = {0, 0, 640, 480};
        SDL_RenderCopy(renderer, texture, nullptr, &rect);

        // 更新窗口显示
        SDL_RenderPresent(renderer);
    }

    // 清理SDL2资源
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}