/**
 * @author yangjian 1171267147@qq.com
 * @brief SDL创建一个窗口，并用图像渲染窗口
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright
 * - https://github.com/Twinklebear/TwinklebearDev-Lessons/blob/master/Lesson1/src/main.cpp
 * - https://adolfans.github.io/sdltutorialcn/blog/2013/01/26/lesson-1-hello-world/
 */
#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <image_file>" << endl;
        return 0;
    }

    spdlog::set_level(spdlog::level::info);

    // 初始化SDL；如果初始化失败，将返回-1，通过SDL_GetError()输出错误消息
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        spdlog::error("Failed to initialize SDL: {}", SDL_GetError());
        return -1;
    }

    // 创建一个窗口,并返回一个SDL_Window窗口的指针,设置窗口标题和窗口位置及大小
    // 设置SDL_WINDOW_SHOWN控制窗口在创建后立刻弹出显示
    SDL_Window* window =
        SDL_CreateWindow("Show Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (nullptr == window)
    {
        spdlog::error("Failed to create window: {}", SDL_GetError());
        return -1;
    }

    // 创建一个渲染器，用来绘制指定的窗口，
    // 并可以指定使用的显卡驱动，设为-1表示让SDL自动选择合适的的显卡驱动
    // SDL_RENDERER_ACCELERATED使用硬件加速，
    // SDL_RENDERER_PRESENTVSYNC与SDL_RenderPresent函数搭配使用，表示使用显示器的刷新率更新画面
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (nullptr == renderer)
    {
        spdlog::error("Failed to create renderer: {}", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // 使用SDL2内置函数加载bmp图像到SDL_Surface中
    SDL_Surface* bmp = SDL_LoadBMP(argv[1]);
    if (nullptr == bmp)
    {
        spdlog::error("Failed to load image: {}", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // 将SDL_Surface转换为SDL_Texture，用来加速图像绘制
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if (nullptr == texture)
    {
        spdlog::error("Failed to create texture: {}", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    for (int i = 0; i < 3; ++i)
    {
        // 清空屏幕
        SDL_RenderClear(renderer);

        // 绘制图片
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);

        SDL_RenderPresent(renderer);

        // 延时，让窗口停留在显示状态
        SDL_Delay(1000);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}