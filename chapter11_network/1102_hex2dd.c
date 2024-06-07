#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXBUF  30
int main(int argc, char **argv)
{
    struct in_addr inaddr;    /* ip address in network byte order */
    uint32_t addr;           /* ip address in host byte order */
    char    buf[MAXBUF];         /* buffer for dotted-decimal string*/
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hex number>\n", argv[0]);
        exit(0);
    }

    sscanf(argv[1], "%x", &addr);
    inaddr.s_addr = htonl(addr);

    if (!inet_ntop(AF_INET, &inaddr, buf, MAXBUF)) {
        printf("inet_ntop error\n");
    }

    printf("%s\n", buf);
    exit(0);
}