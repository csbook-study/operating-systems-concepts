#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(int argc, char **argv) {
  const char *shd_name = "os";
  pid_t pid;
  int shm_fd;
  void *ptr;

  shm_fd = shm_open(shd_name, O_CREAT | O_RDWR, 0666);
  ftruncate(shm_fd, SHM_SIZE);
  ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork failed.\n");
    return 1;
  } else if (pid == 0) {
    int start_num;
    int count;
    char *nums = (char *)malloc(sizeof(char) * 128);

    scanf("%d", &start_num);
    for (count = 0; start_num >= 1; count++) {
      char temp[128];
      sprintf(temp, "%d", start_num);
      nums = strcat(nums, temp);
      if (start_num == 1) {
        break;
      } else {
        nums = strcat(nums, " ");
      }
      if (start_num % 2 == 0) {
        start_num /= 2;
      } else {
        start_num = 3 * start_num + 1;
      }
    }
    // 1.print result
    printf("child print:%s.\n", nums);
    // 2.write to shm
    sprintf(ptr, "%s", nums);
    ptr += strlen(nums);
    printf("child write to shm:%s.\n", nums);
  } else {
    wait(NULL);
    printf("parent print:%s.\n", (char *)ptr);
    shm_unlink(shd_name);
  }

  return 0;
}