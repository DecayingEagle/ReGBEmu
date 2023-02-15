//
// Created by roza0 on 2/14/2023.
//
#include <SDL_syswm.h>
#include "util.h"

#define ID_LOADROM 1
#define ID_ABOUT 2
#define ID_EXIT 3
#define ID_CONTROLS 4
HMENU hHelp;
HMENU hEdit;
HMENU hFile;
HMENU hMenuBar;


//Function which retrieves the address/Handle of an SDL window
//Also retrieves the specific subsystem used by SDL to create that window which is platform specific (Windows, MAC OS x, IOS, etc...)
HWND getSDLWinHandle(SDL_Window* win)
{
    SDL_SysWMinfo infoWindow;
    SDL_VERSION(&infoWindow.version);
    if (!SDL_GetWindowWMInfo(win, &infoWindow))
    {
        return NULL;
    }
    return (infoWindow.info.win.window);
}

//Initializes the native windows drop down menu elements of the window
void ActivateMenu(HWND windowRef)
{
    hMenuBar = CreateMenu();
    hFile = CreateMenu();
    hEdit = CreateMenu();
    hHelp = CreateMenu();

    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hFile, "File");
    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hEdit, "Edit");
    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hHelp, "Help");

    AppendMenu(hFile, MF_STRING, ID_LOADROM, "Load ROM");
    AppendMenu(hFile, MF_STRING, ID_EXIT, "Exit");

    AppendMenu(hEdit, MF_STRING, ID_CONTROLS, "Configure Controls");

    AppendMenu(hHelp, MF_STRING, ID_ABOUT, "About");

    SetMenu(windowRef, hMenuBar);
}


void GenerateConfig(){
    FILE *fp = fopen(CONFIG_FILE, "a");
    fprintf(fp,"up:w \n");
    fprintf(fp,"down:s \n");
    fprintf(fp,"left:a \n");
    fprintf(fp,"right:d \n");
    fprintf(fp,"vol:100 \n");
    fclose(fp);
}

void GetConfig(){
    FILE *fp = fopen(CONFIG_FILE, "r");
    if (fp == NULL)
    {
        GenerateConfig();
    }

    char line[1024] = { 0 };
    while (!feof(fp))
    {
        memset(line, 0, 1024);
        fgets(line, 1024, fp);
        if (line[0] == '#')
        {
            continue;
        }

        int len = strlen(line);
        char *pos = strchr(line, ':');
        if (pos == NULL)
        {
            continue;
        }
        char key[64] = { 0 };
        char val[64] = { 0 };

        int offset = 1;
        if (line[len - 1] == '\n')
        {
            offset = 2;
        }

        strncpy(key, line, pos - line);
        strncpy(val, pos + 1, line + len - offset - pos);

        printf("%s -> %s\n", key, val);
    }
}


