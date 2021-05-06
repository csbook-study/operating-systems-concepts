#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  // open in and out file:inname outname.
  char *inname;
  char *outname;
  if (argc != 3) {
    inname = (char *)malloc(sizeof(char) * 128);
    outname = (char *)malloc(sizeof(char) * 128);
    scanf("%s%s", inname, outname);
  } else {
    inname = argv[1];
    outname = argv[2];
  }
  int fdin = open(inname, O_RDONLY);
  if (-1 == fdin) {
    perror("error to open in file.\n");
    exit(-1);
  }
  int fdout = open(outname, O_WRONLY | O_CREAT, 00700);
  if (-1 == fdout) {
    perror("error to open out file.\n");
    exit(-1);
  }

  // read inname file and output outname file.
  char buf[128];
  while (1) {
    int ret = read(fdin, buf, 127);
    if (-1 == ret) {
      perror("error to read infile.\n");
      exit(-1);
    } else if (0 == ret) {
      printf("copy completely.\n");
      break;
    }

    ret = write(fdout, buf, ret);
    if (-1 == ret) {
      perror("error to write outfile.\n");
      exit(-1);
    }
  }

  close(fdin);
  close(fdout);

  return 0;
}
