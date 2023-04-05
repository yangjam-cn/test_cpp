/**
 * @author yangjian 1171267147@qq.com
 * @brief SDL窗口显示基本框架
 * @version 0.1
 * @date 2023-04-05
 *
 * @copyright Copyright (c) 2023
 */
#ifndef __SDL_FRAMEWORK_HPP__
#define __SDL_FRAMEWORK_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <spdlog/spdlog.h>

#include <map>
#include <string>

const int DEFAULT_WIDTH  = 1280;
const int DEFAULT_HEIGHT = 720;

typedef unsigned int TextureIndex;
const TextureIndex   INVALID_TEXTURE = 0;

class CSdlFrameworkBase {
public:
    CSdlFrameworkBase() {}
    virtual ~CSdlFrameworkBase()
    {
        for (auto texture : m_texturesMap)
            SDL_DestroyTexture(texture.second);
        m_texturesMap.clear();

        if (m_pRenderer != nullptr)
            SDL_DestroyRenderer(m_pRenderer);

        if (m_pWindow != nullptr)
            SDL_DestroyWindow(m_pWindow);

        SDL_Quit();
    }

    /**
     * @brief 初始化窗口和渲染器
     * @param title 窗口标题
     * @param x 窗口起始位置
     * @param y 窗口起始位置
     * @param w 窗口宽
     * @param h 窗口高
     * @return int
     * - 0 成功
     * - -1 失败
     */
    virtual int Init(std::string title = "SDL Framework", int x = SDL_WINDOWPOS_UNDEFINED,
                     int y = SDL_WINDOWPOS_UNDEFINED, int w = DEFAULT_WIDTH, int h = DEFAULT_HEIGHT)
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            spdlog::error("Failed to initialize SDL: {}", SDL_GetError());
            return -1;
        }

        m_pWindow = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_SHOWN);
        if (nullptr == m_pWindow)
        {
            spdlog::error("Failed to create window: {}", SDL_GetError());
            return -1;
        }

        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (nullptr == m_pRenderer)
        {
            spdlog::error("Failed to create renderer: {}", SDL_GetError());
            return -1;
        }
        return 0;
    }

    virtual void Run() = 0;

    /**
     * @brief 手动释放对象管理的纹理
     * @param index
     */
    void FreeTextures(TextureIndex index)
    {
        if (m_texturesMap.find(index) == m_texturesMap.end())
        {
            spdlog::warn("This texture was not found!");
            return;
        }
        SDL_DestroyTexture(m_texturesMap[index]);
        m_texturesMap.erase(index);
    }

protected:
    /**
     * @brief 加载纹理
     * @param path 图片路径
     * @return 纹理序号，通过该序号访问对象管理的纹理
     */
    TextureIndex LoadTexture(std::string path)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (nullptr == surface)
        {
            spdlog::error("Failed to load image: {}", SDL_GetError());
            return INVALID_TEXTURE;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_pRenderer, surface);
        SDL_FreeSurface(surface);
        if (texture == nullptr)
        {
            spdlog::error("Failed to create texture: {}", SDL_GetError());
            return INVALID_TEXTURE;
        }
        TextureIndex index = (TextureIndex)m_texturesMap.size() + 1;
        m_texturesMap.insert(std::pair<TextureIndex, SDL_Texture*>(index, texture));
        return index;
    }

    /**
     * @brief 将纹理中指定区域渲染到窗口指定区域
     * @param texture 纹理指针
     * @param src 窗口矩形区域，nullptr表示整个窗口
     * @param dst 纹理的矩形区域，nullptr表示整幅纹理
     */
    void RenderTexture(SDL_Texture* texture, SDL_Rect* texRect, SDL_Rect* winRect)
    {
        if (texture != nullptr)
            SDL_RenderCopy(m_pRenderer, texture, texRect, winRect);
    }

    /**
     * @brief 将纹理中指定区域渲染到窗口指定区域
     * @param index 纹理序号，调用对象接口生成纹理时返回值
     * @param texRect 纹理的矩形区域，nullptr表示整幅纹理
     * @param winRect 窗口矩形区域，nullptr表示整个窗口
     */
    void RenderTexture(TextureIndex index, SDL_Rect* texRect, SDL_Rect* winRect)
    {
        if (m_texturesMap.size() > 0 && m_texturesMap.find(index) != m_texturesMap.end())
        {
            if (m_texturesMap[index] != nullptr)
                SDL_RenderCopy(m_pRenderer, m_texturesMap[index], texRect, winRect);
            else
                spdlog::warn("This texture is null!");
        }
        else
            spdlog::warn("This texture was not found!");
    }

protected:
    SDL_Window*   m_pWindow   = nullptr;
    SDL_Renderer* m_pRenderer = nullptr;

    std::map<TextureIndex, SDL_Texture*> m_texturesMap;
};

#endif