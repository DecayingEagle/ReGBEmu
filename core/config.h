#ifndef REGB_CONFIG_H
#define REGB_CONFIG_H

#define CONFIG_FILE "config.cfg"

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int up_key;
    int down_key;
    int left_key;
    int right_key;
    int confirm_key;
    int back_key;
    int volume;
} Config;

void GenConfFile();
Config ReadConfigFile();
void UpdateConfigFile(Config* config, int up_key, int down_key, int left_key, int right_key, int confirm_key, int back_key, int volume);
#endif //REGB_CONFIG_H
