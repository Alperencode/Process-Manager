#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "InputParser.h"
#include "Errors.h"

void Execute();
void Start(char** args);

#endif
