//
// Created by roza0 on 2/14/2023.
//
#include "util.h"



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


