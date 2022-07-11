#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXLINE 4096

int main(int argc, char** argv) {
  int sockfd, n;
  char recvline[MAXLINE], sendline[MAXLINE];
  char buff[MAXLINE];
  struct sockaddr_in servaddr;

  if (argc != 2) {
    argv[1] = "127.0.0.1";
  }

  while (1) {
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      printf("create socket error:%s(errno:%d).\n", strerror(errno), errno);
      return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
      printf("inet_pton error for %s.\n", argv[1]);
      return 0;
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
      printf("connect socket error:%s(errno:%d).\n", strerror(errno), errno);
      return 0;
    }
    printf("send msg to server:");
    fgets(sendline, MAXLINE, stdin);
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
      printf("send msg error:%s(errno:%d).\n", strerror(errno), errno);
      return 0;
    }
    n = recv(sockfd, buff, MAXLINE, 0);
    buff[n] = '\0';
    printf("recv msg from server:%s\n", buff);
    close(sockfd);
  }

  return 0;
}