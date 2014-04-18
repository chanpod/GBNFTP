#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MYPORT "10030"    // the port users will be connecting to

#define MAXBUFLEN 100


int receive(int numBytes, char *buf, struct addrinfo *p, int sockfd);
void writeToFile(FILE *fr, char *toAdd, int numbytes, int sizeOfBuf);
char* checkForGet(char *packetIn);
void replyWithInvalidFile(struct addrinfo *p, int sockfd);


char* makeChecksum(char* message);
char * damage(char **p);
int gremlin(float damaged, float lost, char ** packet);

float damaged = 0;
float lost = 0;

/*
Call with: PORT prob prob
*/
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}