//Using SDL and standard IO
#include <SDL.h>
#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include "core/util.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TITLE "ReGB"

bool isRunning = true;
SDL_Event e;
HWND windowHandler;

int input() {
    const uint8_t *keystates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&e)) {
        if((e.type == SDL_QUIT) | keystates[SDL_SCANCODE_ESCAPE]) return 1;
    }
}

int main(int argc, char* args[]) {
    GetConfig();
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow(
            TITLE,
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );
    if (window == NULL) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return 1;
    }
    windowHandler = getSDLWinHandle(window);
    ActivateMenu(windowHandler);
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
    SDL_bool done = SDL_FALSE;
    while (!done) {
        if (input()) {
            done = SDL_TRUE;
        };
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}