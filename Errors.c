#include "Errors.h"

void die(const char *errorMessage){
    perror(errorMessage);
    exit(1);
}

void clear(){
    system("clear");
}
