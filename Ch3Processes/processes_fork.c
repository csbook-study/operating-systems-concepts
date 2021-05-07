#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t pid;
  // fork a child process
  pid = fork();
  if (pid < 0) {
    // err occurred
    fprintf(stderr, "fork failed.\n");
    return 1;
  } else if (pid == 0) {
    // child process
    execlp("/bin/ls", "ls", NULL);
  } else {
    // parent process
    // parent process will wait for the child to complete
    wait(NULL);
    printf("child complete.\n");
  }

  return 0;
}