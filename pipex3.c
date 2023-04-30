#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s file1 cmd1 cmd2 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *file1 = argv[1];
    char *cmd1[] = { "/bin/sh", "-c", argv[2], NULL };
    char *cmd2[] = { "/bin/sh", "-c", argv[3], NULL };
    char *file2 = argv[4];

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
        // child 1
        close(pipefd[0]);
        if (dup2(open(file1, O_RDONLY), STDIN_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        execvp(cmd1[0], cmd1);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // child 2
        close(pipefd[1]);
        if (dup2(pipefd[0], STDIN_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        if (dup2(open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        execvp(cmd2[0], cmd2);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // parent
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
