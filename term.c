// remaking bc idk how code works
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<signal.h>

#define MAX_COMMAND_LENGTH 1024

void execute_command(const char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
    } else if (pid == 0) {
        // child process
        execlp(command, command, NULL);
        perror("Exec failed");
        exit(1);
    } else {
        // parent process
        wait(NULL);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command (or type 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);

        //remove newline character
        size_t length = strlen(command);
        if (length > 0 && command[length - 1] == '\n') {
            command[length - 1] = '\0';
        }

        // exit loop if user enters 'exit'
        if (strcmp(command, "exit") == 0){
            break;
        }

        // execute entered command
        execute_command(command);
    }

    return 0;
}
