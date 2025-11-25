#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands.h"
#include "utils.h"

#define MAX_INPUT 256

int main() {
    char input[MAX_INPUT];

    printf("O‘zbekcha Mini-Shellga xush kelibsiz!\n");
    printf("Komandalar ro‘yxati uchun: yordam\n");

    int cmd_count;
    Command *cmds = get_commands(&cmd_count);

    while (1) {
        printf("mini-os> ");
        if (!fgets(input, MAX_INPUT, stdin)) continue;
        trim_newline(input);

        char *command = strtok(input, " ");
        char *args = strtok(NULL, "");

        if (!command) continue;

        int found = 0;

        for (int i = 0; i < cmd_count; i++) {
            if (strcmp(command, cmds[i].name) == 0) {
                cmds[i].func(args);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("Xatolik: '%s' komanda mavjud emas.\n", command);
    }

    return 0;
}
