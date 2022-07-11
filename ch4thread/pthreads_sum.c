#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
void *runner(void *param);

int main(int argc, char **argv) {
  pthread_t tid;
  pthread_attr_t attr;
  char *num;

  if (argc != 2) {
    num = (char *)malloc(sizeof(char) * 128);
    scanf("%s", num);
  } else {
    num = argv[1];
  }

  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, runner, num);
  pthread_join(tid, NULL);

  printf("sum:%d.\n", sum);

  return 0;
}

void *runner(void *param) {
  int upper = atoi(param);
  printf("upper:%d.\n", upper);
  sum = 0;
  for (int i = 1; i <= upper; i++) {
    sum += i;
  }
  pthread_exit(0);
}