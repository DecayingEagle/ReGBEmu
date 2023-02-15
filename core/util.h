//
// Created by roza0 on 2/14/2023.
//

#ifndef REGB_UTIL_H
#define REGB_UTIL_H

#define CONFIG_FILE "config.cfg"

#include <SDL.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


HWND getSDLWinHandle(SDL_Window* win);
void ActivateMenu(HWND windowRef);
void GetConfig();

#endif //REGB_UTIL_H
