#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PAGESIZE 4096

#define EXIT_ERR_MAP_FAILED 1
#define EXIT_ERR_FORK_FAILED 2
#define EXIT_ERR_WAIT_FAILED 3
#define EXIT_ERR_SYNC_FAILED 4

int a = 5;

int main(int argc, char** argv) {
  pid_t childPid = fork();
  int wstatus;

  if (childPid == -1) {
    fprintf(stderr, "fork error.\n");
    exit(EXIT_ERR_FORK_FAILED);
  }

  bool isChildProcess = childPid == 0;

  uint8_t* b = (uint8_t*)(mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
                               MAP_SHARED | MAP_ANONYMOUS, -1, 0));

  if (b == MAP_FAILED) {
    fprintf(stderr, "mmap error.\n");
    exit(EXIT_ERR_MAP_FAILED);
  }

  *b = 34;

  if (isChildProcess) {
    a = 100;
    *b = 15;

    if (msync(b, PAGESIZE, MS_SYNC) == -1) {
      fprintf(stderr, "msync error.\n");
      exit(EXIT_ERR_SYNC_FAILED);
    }
  } else {
    printf("WAITING FOR CHILD.\n");
    if (waitpid(childPid, &wstatus, 0) == -1) {
      fprintf(stderr, "wait error.\n");
      exit(EXIT_ERR_WAIT_FAILED);
    }
    printf("DONE WAITING\n");
  }
  if (isChildProcess) {
    printf("Reading from child process. `a`: %i (not shared)\n", a);
    printf(
        "Reading from child process. `b`: %i (shared between parent process "
        "and child process)\n",
        *b);
    exit(EXIT_SUCCESS);
  } else {
    printf("Reading from parent process. `a`: %i (not shared)\n", a);
    printf(
        "Reading from parent process. `b`: %i (shared between parent process "
        "and child process)\n",
        *b);
  }

  exit(EXIT_SUCCESS);
}