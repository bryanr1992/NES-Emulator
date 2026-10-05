#pragma once

#include <SDL3/SDL.h>

class Client {
public:
    Client(const char* windowName, int width, int height);
    ~Client();
public:
    void update();
    
private:
    SDL_Window* m_Window{};
    SDL_Renderer* m_Renderer{};
};
