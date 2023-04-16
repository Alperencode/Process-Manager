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

    // int argSize = sizeof(args) / sizeof(char**); 

    if(strcmp(args[0], "start") == 0){
        Start(args);
    }else if(strcmp(args[0], "stop") == 0){
        // Stop(args);
    }else if(strcmp(args[0], "signal") == 0){
        // Signal(args);
    }else if(strcmp(args[0], "info") == 0){
        // Info(args);
    }else if(strcmp(args[0], "list") == 0){
        // List(args);
    }else if(strcmp(args[0], "help") == 0){
        // Help();
    }else{
        // InputError();
    }

}

void Start(char **args){
    // Usage of this function could be changed later
    // And it still has some bugs
    int status = 0;

    // Creating child process to execute command
    pid_t pid = fork();

    if(pid < 0)
        die("Fork error [START]");
    
    else if(pid == 0){
        // Child process
        if(execvp(args[1], args) == -1) die("Execution error [START]");
    }
    else
        // Parent process
        do{
            // Parent process waits until child process finish
            waitpid(pid, &status, WUNTRACED);

            // WIFEXITED   : program exited
            // WIFSIGNALED : program killed by signal 
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));

}
