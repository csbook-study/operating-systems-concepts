#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(int argc, char **argv) {
  char write_msg[BUFFER_SIZE] = "greeting";
  char read_msg[BUFFER_SIZE];
  int fd[2];
  pid_t pid;

  // create the pipe
  if (pipe(fd) == -1) {
    fprintf(stderr, "pipe failed.\n");
    return 1;
  }
  // fork a child process
  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork failed.\n");
    return 1;
  } else if (pid > 0) {
    // parent process
    // close unused end of the pipe
    close(fd[READ_END]);
    // write to the pipe
    write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
    // close the read end of the pipe
    close(fd[WRITE_END]);
  } else {
    // child process
    // close unused end of the pipe
    close(fd[WRITE_END]);
    // read from the pipe
    read(fd[READ_END], read_msg, BUFFER_SIZE);
    printf("%s\n", read_msg);
    // close the write end of pipe
    close(fd[READ_END]);
  }

  return 0;
}
