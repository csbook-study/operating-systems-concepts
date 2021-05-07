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
  // strings written to shared memory
  const char *message_0 = "hello";
  const char *message_1 = "world";

  // shared memory file descriptor
  int shm_fd;
  // pointer to shared memory object
  void *ptr;

  // create the shared memory object
  shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
  // configure the size of the shared memory object
  ftruncate(shm_fd, size);
  // memory map the shared memory object
  ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);

  // write to the shared memory object
  sprintf(ptr, "%s", message_0);
  ptr += strlen(message_0);  // 指针移位
  sprintf(ptr, "%s", message_1);
  ptr += strlen(message_1);  // 指针移位

  return 0;
}