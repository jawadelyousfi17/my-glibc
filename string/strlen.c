#include "f_string.h"

size_t f_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}