#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <command1> <command2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Child process 1 (read from file)
        close(pipefd[0]); // Close read end of pipe
        int infile = open(argv[1], O_RDONLY);
        dup2(infile, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close(infile);
        close(pipefd[1]);
        execl("/bin/sh", "sh", "-c", argv[2], NULL);
        perror("exec");
        exit(EXIT_FAILURE);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Child process 2 (write to file)
        close(pipefd[1]); // Close write end of pipe
        int outfile = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
        dup2(pipefd[0], STDIN_FILENO);
        dup2(outfile, STDOUT_FILENO);
        close(outfile);
        close(pipefd[0]);
        execl("/bin/sh", "sh", "-c", argv[3], NULL);
        perror("exec");
        exit(EXIT_FAILURE);
    }

    // Parent process
    close(pipefd[0]); // Close both ends of pipe
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
