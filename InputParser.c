#include "InputParser.h"

char** GetInput(){
    char input[1024];

    printf("\n> ");
    fflush(stdout);
    fgets(input, sizeof(input), stdin);

    return ParseInput(input);
}

char** ParseInput(char *input){
    int position = 0;
    int bufsize = PI_BUFSIZE;

    char** tokens = malloc(sizeof(char*) * bufsize);
    char* token;

    if(!tokens) die("Allocation error [ParseInput Error]");

    token = strtok(input, " ");

    while(token != NULL){
        tokens[position] = token;
        position += 1;

        if(position >= bufsize){
            bufsize += PI_BUFSIZE;
            tokens = realloc(tokens, sizeof(char*) * bufsize);
            if(!tokens) die("Allocation error [ParseInput Error]");
        }
        token = strtok(NULL, " ");
    }

    tokens[position] = NULL;
    return tokens;
}

