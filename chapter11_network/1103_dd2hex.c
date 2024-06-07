#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    struct in_addr inaddr;      /* address in network byte order */
    uint32_t    addr;           /* address in host byte order */

    if ( argc != 2) {
        fprintf(stderr, "usage: %s <dotted-decimal ip>\n", argv[0]);
        exit(0);
    }
    inet_pton(AF_INET, argv[1], &inaddr);
    addr = ntohl(inaddr.s_addr);

    printf("0x%x\n", addr);
    exit(0);
}