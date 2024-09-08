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

#define MAXLINE 4096
#define SERVER_PORT 18000

#define EXIT_ERR_SOCK_INIT 2
#define EXIT_ERR_SOCK_BIND 3
#define EXIT_ERR_SOCK_LISTEN 4
#define EXIT_ERR_SOCK_WRITE 5
#define EXIT_ERR_SOCK_READ 6
#define EXIT_ERR_SOCK_CLOSE 7

char *bin2hex(const unsigned char *input, size_t len) {
  char *result;
  char *hexits = "0123456789ABCDEF";

  if (input == nullptr || len <= 0) {
    return nullptr;
  }

  int resultlength = (len * 3) + 1;

  result = new char[resultlength];
  memset(result, 0, resultlength);

  for (int i = 0; i < len; i++) {
    result[i * 3] = hexits[input[i] >> 4];
    result[(i * 3) + 1] = hexits[input[i] & 0x0F];
    result[(i * 3) + 2] = ' ';
  }

  return result;
}

int main(int argc, char **argv) {
  int listenfd, connfd, bytesread;
  struct sockaddr_in servaddr;
  uint8_t buff[MAXLINE + 1];
  uint8_t recvline[MAXLINE + 1];

  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "socket initialisation failed.\n");
    exit(EXIT_ERR_SOCK_INIT);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(SERVER_PORT);

  // Associate the server IPv4 address with the socket.
  if ((bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) < 0) {
    fprintf(stderr, "socket bind failed.\n");
    exit(EXIT_ERR_SOCK_BIND);
  }

  if ((listen(listenfd, 10)) < 0) {
    fprintf(stderr, "socket listen failed.\n");
    exit(EXIT_ERR_SOCK_LISTEN);
  }

  while (true) {
    struct sockaddr_in addr;
    socklen_t addr_len;

    // Accept blocks until an incoming connection arrives.
    // It returns a "file descriptor" to the connection.
    printf("waiting for a connection on port %d", SERVER_PORT);
    fflush(stdout);
    connfd = accept(listenfd, (struct sockaddr *)nullptr, nullptr);

    memset(recvline, 0, MAXLINE);
    // Read from the connected socket.
    while ((bytesread = read(connfd, recvline, MAXLINE - 1)) > 0) {
      fprintf(stdout, "\n%s\n\n%s", bin2hex(recvline, bytesread), recvline);

      // Detect end of HTTP request.
      if (recvline[bytesread - 1] == '\n') {
        break;
      }
      memset(recvline, 0, MAXLINE);
    }

    if (bytesread < 0) {
      fprintf(stderr, "socket read failed.\n");
      exit(EXIT_ERR_SOCK_READ);
    }

    // Send the response.
    snprintf((char *)buff, sizeof(buff), "HTTP/1.0 200 OK\r\n\r\nHello");
    while (true) {
      int bytessent = write(connfd, (char *)buff, strlen((char *)buff));
      if (bytessent < 0) {
        fprintf(stderr, "socket write failed.\n");
        exit(EXIT_ERR_SOCK_WRITE);
      }
      if (bytessent == strlen((char *)buff)) break;
    }

    if (close(connfd) < 0) {
      fprintf(stderr, "socket close failed.\n");
      exit(EXIT_ERR_SOCK_CLOSE);
    }
  }
}
