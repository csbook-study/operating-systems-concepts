#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 128
#define P_FIFO "/tmp/p_fifo"

int main(int argc, char **argv) {
  int fd;
  char cache[BUFFER_SIZE];

  if (access(P_FIFO, F_OK) == 0) {
    execlp("rm", "-f", P_FIFO, NULL);
    printf("access.\n");
  }
  if (mkfifo(P_FIFO, 0777) < 0) {
    printf("create named pipe failed.\n");
  }
  fd = open(P_FIFO, O_RDONLY | O_NONBLOCK);
  while (1) {
    memset(cache, 0, sizeof(cache));
    if ((read(fd, cache, BUFFER_SIZE)) == 0 || strlen(cache) == 0) {
      printf("no data.\n");
    } else {
      printf("get data:%s.\n", cache);
    }
    sleep(1);
  }
  close(fd);

  return 0;
}