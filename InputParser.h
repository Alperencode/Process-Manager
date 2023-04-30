#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Errors.h"

#define PI_BUFSIZE 64

char** GetInput();
char** ParseInput(char*);

#endif
