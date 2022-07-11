#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128
#define P_FIFO "/tmp/p_fifo"

int main(int argc, char **argv) {
  int fd;
  char str[BUFFER_SIZE];

  fd = open(P_FIFO, O_WRONLY | O_NONBLOCK);
  while (scanf("%s\n", str)) {
    write(fd, str, strlen(str) + 1);
  }
  close(fd);

  return 0;
}