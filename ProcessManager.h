#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#include "Errors.h"
#include "InputParser.h"

void Execute();
int Start(char** args);
int Stop(char** args);
char** RemoveSignalElement(char **args);

#endif
