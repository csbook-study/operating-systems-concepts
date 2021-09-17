#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// 构造守护进程
void InitDaemon() {
  pid_t pid;
  // 1. 创建子进程，父进程退出
  pid = fork();
  if (pid == -1) {
    printf("fork err\n");
    exit(-1);
  } else if (pid != 0) {
    exit(0);
  }

  // 2. 子进程开启新会话，并成为会话首进程和组长进程
  setsid();
  pid = fork();
  if (pid == -1) {
    printf("fork err\n");
    exit(-1);
  } else if (pid != 0) {
    exit(0);
  }

  // 3. 改变工作目录
  chdir("/tmp");
  // 4. 重设文件掩码
  umask(0);
  // 5. 子进程关闭打开的文件描述符
  for (int i = 0; i < getdtablesize(); ++i) {
    close(i);
  }

  return;
}

int main(int argc, char **argv) {
  int fp;
  time_t t;
  char buf[] = {"this is a daemon:"};
  char *datetime;
  int len = 0;

  // 初始化 daemon 进程
  InitDaemon();

  // 每隔一分钟记录运行状态
  while (1) {
    if (-1 ==
        (fp = open("/tmp/daemon.log", O_CREAT | O_WRONLY | O_APPEND, 0600))) {
      printf("open file error\n");
      exit(1);
    }
    len = strlen(buf);
    write(fp, buf, len);
    t = time(0);
    datetime = asctime(localtime(&t));
    len = strlen(datetime);
    write(fp, datetime, len);
    close(fp);
    sleep(60);
  }

  return 0;
}