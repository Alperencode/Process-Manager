#include <unistd.h>
#include <stdio.h>

int main(){

    // First child process
    int pid = fork();

    if(pid==0){
        // Second child process under first child
        int pid2 = fork();
        printf("pid: %d pid2: %d\n", pid, pid2);
    }else
        printf("pid: %d\n", pid);

    while(1);
    return 0;

}
