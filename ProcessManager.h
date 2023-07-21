#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#include "Errors.h"
#include "InputParser.h"

void Execute();
int Start(char** args);
int Stop(char** args);
void List();
char** RemoveSignalElement(char **args);

#endif
