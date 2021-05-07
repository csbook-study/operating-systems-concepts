#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
  // the size (in bytes) of shared memory object
  const int size = 4096;
  // name of shared memory object
  const char *name = "os";

  // shared memory file descriptor
  int shm_fd;
  // pointer to shared memory object
  void *ptr;

  // create the shared memory object
  shm_fd = shm_open(name, O_CREAT | O_RDONLY, 0666);
  // configure the size of the shared memory object
  ftruncate(shm_fd, size);
  // memory map the shared memory object
  ptr = mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);

  // read from the shared memory object
  printf("%s\n", (char *)ptr);

  // remove the shared memory object
  shm_unlink(name);

  return 0;
}