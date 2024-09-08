#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVER_PORT 80

#define MAXLINE 4096  // Buffer for reading.

#define EXIT_ERR_INSUFFICIENT_ARGS 1
#define EXIT_ERR_SOCK_INIT 2
#define EXIT_ERR_ADDR_TRANSLATION 3
#define EXIT_ERR_SOCK_CONNECT 4
#define EXIT_ERR_SOCK_WRITE 5
#define EXIT_ERR_SOCK_READ 6

int main(int argc, char** argv) {
  int sockfd, bytesread, sendbytes;
  struct sockaddr_in servaddr;
  char sendline[MAXLINE], recvline[MAXLINE];

  if (argc != 2) {
    fprintf(stderr, "usage: %s <server address>\n", argv[0]);
    exit(EXIT_ERR_INSUFFICIENT_ARGS);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "socket initialisation failed.\n");
    exit(EXIT_ERR_SOCK_INIT);
  }

  memset(&servaddr, 0, sizeof(servaddr));  // Zero out the server struct.
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERVER_PORT);

  // Translates string representation of an IPv4 address into a binary network
  // representation.
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "address translation failed.\n");
    exit(EXIT_ERR_ADDR_TRANSLATION);
  }

  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    fprintf(stderr, "socket connect failed.\n");
    exit(EXIT_ERR_SOCK_CONNECT);
  }

  sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
  sendbytes = strlen(sendline);

  while (true) {
    int bytessent = write(sockfd, sendline, sendbytes);
    if (bytessent < 0) {
      fprintf(stderr, "socket write failed.\n");
      exit(EXIT_ERR_SOCK_WRITE);
    }
    if (bytessent == sendbytes) break;
  }

  memset(recvline, 0, MAXLINE);

  while ((bytesread = read(sockfd, recvline, MAXLINE - 1)) > 0) {
    printf("%s", recvline);
    memset(recvline, 0, MAXLINE);
  }

  if (bytesread < 0) {
    fprintf(stderr, "socket read failed.\n");
    exit(EXIT_ERR_SOCK_READ);
  }

  exit(EXIT_SUCCESS);
}