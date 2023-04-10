#include "ProcessManager.h"

void Execute(){

    char **args = GetInput();

    /*
    - `start <command>`: Starts a new process with the specified command.
    - `stop <pid>`: Stops the process with the specified process ID (PID).
    - `signal <pid> <signal>`: Sends a signal to the process with the specified PID.
    - `info <pid>`: Displays information about the process with the specified PID.
    - `list`: Displays a list of all running processes.
    - `help`: Displays a list of available commands.
    */

    int argSize = sizeof(args) / sizeof(char**); 

    if(strcmp(args[0], "start") == 0){
        // Handle start
        Start(args, argSize);
    }else if(strcmp(args[0], "stop") == 0){
        // Handle stop
        Stop(args, argSize);
    }else if(strcmp(args[0], "signal") == 0){
        // Handle signal
        Signal(args, argSize);
    }else if(strcmp(args[0], "info") == 0){
        // Handle info
        Info(args, argSize);
    }else if(strcmp(args[0], "list") == 0){
        // Handle list
        List(args, argSize);
    }else if(strcmp(args[0], "help") == 0){
        // Handle help
        Help();
    }else{
        // Handle error
        InputError();
    }

}

void Start(char **args, int argSize){


}
