//COEN 146L : Lab3, step 1: TCP client requesting a file transfer from the server.
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    //Get from the command line, server IP, src and dst files.
    if (argc != 5){
		printf ("Usage: %s <ip of server> <port #> <src_file> <dest_file>\n",argv[0]);
		exit(0);
    } 
    //Declare socket file descriptor and buffer
    int sockfd, nr;
    char buf[10];

    //Declare server address to accept
    struct sockaddr_in servAddr;

   //Declare host
    struct hostent *host;

    //get hostname
    host = (struct hostent *) gethostbyname(argv[1]); 

    //Open a socket, if successful, returns
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
		perror("Failed to open endpoint");
		exit(0);
	}

    //Set the server address to send using socket addressing structure
    servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(atoi(argv[2]));
	servAddr.sin_addr = *((struct in_addr *) host->h_addr);    

    //Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(struct sockaddr)))
	{
		perror("Failure to connect to the server");
		exit(1);
	}
    //Client sends the name of the file to retrieve from the server
    write(sockfd, argv[3], strlen(argv[3])+1);

    //Client begins to write and read from the server
    FILE *chk = fopen(argv[4], "a");
	//int bytes;
	while((nr = read(sockfd, buf, sizeof(buf))) > 0){
        	fwrite(&buf, nr, 1, chk);
    	}
    //Close socket descriptor
    fclose(chk);
    close(sockfd);
    return 0;
}

