#include "f_string.h"

size_t f_strlen(const char *s)
{
    char *c;
    size_t len = 0;
    while (*s != '\0')
        s++;
    return (size_t) c - s;
}
