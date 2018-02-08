#ifndef splitStringHeader
#define splitStringHeader

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

size_t splitString(char **input, char ***output);
size_t splitStringWith(char **input, char ***output, char **delimiter);

#endif // splitStringHeader
