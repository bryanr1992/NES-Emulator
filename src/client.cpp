#include "client.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <optional>
//#include <SDL3/SDL_error.h>
//#include <SDL3/SDL_log.h>
//#include <SDL3/SDL_video.h>

Client::Client(const char* windowName, int width, int height) {
    //SDL Initialization
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "Couldn't initialize SDL, %s", 
                     SDL_GetError());
    }

    m_Window = SDL_CreateWindow(windowName, width, height, SDL_WINDOW_RESIZABLE);
    if(m_Window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create window and renderer %s",
                     SDL_GetError());
    }

    //Create renderer. Without this an empty window won't show on wayland.
    //This happens because wayland by default keeps the window hidden until
    //after something is drawn into it. The compositor only shows a window after
    //the app gives it its first frame
    m_Renderer = SDL_CreateRenderer(m_Window, nullptr);
    if (m_Renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create renderer %s",
                     SDL_GetError());
    }

}

void Client::update() {
    SDL_SetRenderDrawColor(m_Renderer, 0,0,0,255);
    SDL_RenderClear(m_Renderer);
    SDL_RenderPresent(m_Renderer);
}

Client::~Client() {
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}
