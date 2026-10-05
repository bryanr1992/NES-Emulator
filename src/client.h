#pragma once

#include <SDL3/SDL.h>

class Client {
public:
    Client(const char* windowName, int width, int height);
    ~Client();
    
private:
    SDL_Window* m_Window{};
};
