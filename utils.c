#include "utils.h"
#include <string.h>

void trim_newline(char *str) {
    if (!str) return;
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
