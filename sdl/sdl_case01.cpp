/**
 * @author yangjian 1171267147@qq.com
 * @brief SDL创建一个窗口和渲染器
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023
 */
#include <SDL2/SDL.h>
int main(int argc, char* argv[])
{
    // 1. 初始化SDL2
    SDL_Init(SDL_INIT_VIDEO);

    // 2. 创建窗口和渲染器
    SDL_Window* window =
        SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 3. 循环处理事件
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
        // 更新窗口显示
        SDL_RenderPresent(renderer);
    }

    // 清理SDL2资源
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}