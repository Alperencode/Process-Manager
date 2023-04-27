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
    
    // Creating child process to execute command
    pid_t pid = fork();

    if(pid < 0)
        die("Fork error [START]");
    
    else if(pid == 0){
        // Child process
        args = RemoveSignalElement(args); // Removes "start" from array
        if(execvp(args[0], args) == -1) die("Execution error [START]");
    }
    else{
        // Parent process
        wait(0);
    }

}

char** RemoveSignalElement(char **args){
    int i;
    // Remove signals: "start", "kill"
    for(i = 0; args[i + 1] != NULL; i++)
        args[i] = args[i + 1];
    args[i] = NULL; 

    // Remove any trailing whitespace
    for (i = 0; args[i] != NULL; i++) {
        int len = strlen(args[i]);
        while (len > 0 && isspace(args[i][len - 1])) {
            args[i][len - 1] = '\0';
            len--;
        }
    }
    return args;
}
