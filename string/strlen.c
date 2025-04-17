#include "f_string.h"

size_t f_strlen(const char *s)
{
    char *c = s;
    while (*s != '\0')
        s++;
    return (size_t) c - s;
}
