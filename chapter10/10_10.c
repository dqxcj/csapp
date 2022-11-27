#include "csapp.h"

int main(int argc, char **argv) {
    int n;
    rio_t rio;
    char buf[MAXLINE];

    Rio_readinitb(&rio, STDIN_FILENO);
    if(argc == 2) {
        int fd = open(argv[1], O_RDONLY | O_CREAT, 0);
        Rio_readinitb(&rio, fd);
    }
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        Rio_writen(STDOUT_FILENO, buf, n);
    }
}