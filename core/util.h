//
// Created by roza0 on 2/14/2023.
//

#ifndef REGB_UTIL_H
#define REGB_UTIL_H

#define CONFIG_FILE "config.cfg"

#define ID_LOADROM 1
#define ID_ABOUT 2
#define ID_RESET 3
#define ID_SHUTDOWN 4
#define ID_EXIT 5
#define ID_SETTINGS 6

#include <SDL.h>
#include <SDL_syswm.h>
#include <windows.h>
#include <commdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


HWND getSDLWinHandle(SDL_Window* win);
UINT getSDLWinMsg(SDL_Window* win);
void ActivateMenu(HWND windowRef);
void GetConfig();
int OpenFileDialog(char filetype[], char title[]);

#endif //REGB_UTIL_H
