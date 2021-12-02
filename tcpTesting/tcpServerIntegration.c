#include <stdio.h>
#include <unistd.h> // for read, write, close, etc
#include <netdb.h>
#include <netinet/in.h> // provides struct sockaddr_in
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> //sockaddr
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
#define SOCK_CLOSE_ERR -1
#define NETLIST_NAME "Netlist.net"
#define NETLIST_PATH "."
#define BUFFER_LENGTH 256


void die(const char* errorMessage, int errNo)
{
	perror("%s", errorMessage);
	exit(errNo);
}


// Driver function
int socketCreation(char *buff) /* or FILE*? */
{
	int sockfd, connfd, len, keepGoing = 1;
	struct sockaddr_in servaddr, cli;

	// create socket
	// AF_INET: address family, accepts IPv4
	// SOCK_STREAM: TCP
	// 0: default protocol, as SOCK_STREAM identifies TCP
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");

	// set all memory to 0 to then add to it
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // allow any IP addr to connect
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server accept failed...\n");
		exit(0);
	}
	else
		printf("server accept the client...\n");

	int n;
	char buf[BUFFER_LENGTH];

	read(connfd, buf, BUFFER_LENGTH);

	printf("%s\n", buf);
	// After chatting close the socket
	if(close(sockfd) != 0)
		return -1;
	if(close(connfd) != 0)
		return -1;
	
	strncpy(buff, buf, sizeof(buf)); // &buff?

	return 1; 
}

int main()
{
	FILE* pNetlistFile;

	char *buffer = (char*)malloc(BUFFER_LENGTH * sizeof(char));
	socketCreation(buffer);
	if(buffer == NULL) // does this work?
		die("Buffer allocation failed", -1)

	pNetlistFile = fopen(NETLIST_NAME, "w+"); // open Netlist.net
	if(!pNetlistFile) // means file was not created
		die("Failed to open file", -1)

	if(fwrite(buffer, 256, 8, pNetlistFile) != (size_t)256) //??
		die("Fwrite failed", -1);
	
	system("ngspice");
	system("source Netlist.net");
	system("op");
	system("print in2");

	fclose(pNetlistFile);
	return 1;

}
