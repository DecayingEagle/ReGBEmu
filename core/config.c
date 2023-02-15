#include "config.h"

Config ReadConfigFile(const char* filename) {
    Config config = {0}; // initialize all members to 0
    char line[100];
    char key[20];
    int value;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return config;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        // ignore comments and blank lines
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }
        // parse key and value from line
        if (sscanf(line, "%s %d", key, &value) != 2) {
            printf("Invalid line in config file: %s", line);
            continue;
        }
        // set the appropriate member of the config struct based on the key
        if (strcmp(key, "up_key") == 0) {
            config.up_key = value;
        } else if (strcmp(key, "down_key") == 0) {
            config.down_key = value;
        } else if (strcmp(key, "left_key") == 0) {
            config.left_key = value;
        } else if (strcmp(key, "right_key") == 0) {
            config.right_key = value;
        } else if (strcmp(key, "confirm_key") == 0) {
            config.confirm_key = value;
        } else if (strcmp(key, "back_key") == 0) {
            config.back_key = value;
        } else if (strcmp(key, "volume") == 0) {
            config.volume = value;
        } else {
            printf("Unknown key in config file: %s", key);
        }
    }
    fclose(file);
    return config;
}

void UpdateConfigFile(Config* config, int up_key, int down_key, int left_key, int right_key, int confirm_key, int back_key, int volume){
    config->up_key = up_key;
    config->down_key = down_key;
    config->left_key = left_key;
    config->right_key = right_key;
    config->confirm_key = confirm_key;
    config->back_key = back_key;
    config->volume = volume;
}