#include "InputParser.h"

char** GetInput(){
    char input[256];

    printf("> ");
    fflush(stdout);
    fgets(input, sizeof(input), stdin);

    return ParseInput(input);
}

char** ParseInput(char *input) {
    int tokenNum = 0;
    char **args = NULL;
    char *token = strtok(input, " ");

    while (token != NULL) {
        args = realloc(args, sizeof(char *) * (tokenNum + 1));
        args[tokenNum++] = token;
        token = strtok(NULL, " ");
    }

    args = realloc(args, sizeof(char*)*(tokenNum + 1));
    args[tokenNum] = NULL;

    return args;
}
