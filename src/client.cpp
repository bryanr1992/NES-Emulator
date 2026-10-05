#include "client.h"

#include <SDL3/SDL.h>
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


}

Client::~Client() {
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}
