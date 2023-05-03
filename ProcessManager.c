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

    char* command = args[0];
    args = RemoveSignalElement(args); // Removes command from args array

    if(strcmp(command, "start") == 0){
        if(Start(args) != 0)
            die("Start command error");
    }else if(strcmp(command, "stop") == 0){
        if(Stop(args) != 0)
            die("Stop command error");
    }else if(strcmp(command, "signal") == 0){
        // Signal(args);
    }else if(strcmp(command, "info") == 0){
        // Info(args);
    }else if(strcmp(command, "list") == 0){
        // List(args);
    }else if(strcmp(command, "help") == 0){
        // Help();
    }else{
        // InputError();
    }

}

/**
 * Start process with given command and arguments
 *
 * @param args Command name to execute and its arguments as string array
 * @return 0 for successfull execution, -1 for any errors
 */
int Start(char **args){
    // Usage of this function could be changed later
    
    // Creating child process to execute command
    pid_t pid = fork();
    int status;

    if(pid < 0)
        // PID Error Case
        return -1;
    else if(pid == 0){
        // Child process
        if(execvp(args[0], args) == -1) return -1;
    }
    else
        // Parent process
        waitpid(pid, &status, 0);

    return 0;
}

/**
 * <Summary>
 *
 * @param args <Summary>
 * @return 0 for successfull execution, -1 for any errors
 */
int Stop(char **args){

    return 0;
}

char** RemoveSignalElement(char **args){
    int i;
    // Remove signals: "start", "kill"
    for(i = 0; args[i + 1] != NULL; i++)
        args[i] = args[i + 1];
    args[i] = NULL; 

    // Remove any trailing whitespace
    for(i = 0; args[i] != NULL; i++){
        int len = strlen(args[i]);
        while(len > 0 && isspace(args[i][len - 1]))
            args[i][len-- - 1] = '\0';
    }
    return args;
}
