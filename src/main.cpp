#include "client.h"
//#include <SDL3/SDL_events.h>

int main(int argc, char* argv[]) {
    Client client("NES WINDOW", 320, 240);
    SDL_Event event;

    while(true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            break;
        }
        if(event.type == SDL_EVENT_KEY_DOWN) {
            SDL_Log("Key Was Pressed!");
            // Retrieve the scan code
            SDL_Log("Keycode: %i", event.key.key);
        }

        client.update();
    }

    return 0;
}
