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


// Driver function
int main()
{
	int sockfd, connfd, len;
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
	char buf[32];

	read(connfd, buf, 32);
	//read(sockfd, buf, 32);

	// Function for chatting between client and server
	//func(connfd);
	
	printf("%s\n", buf);

	// After chatting close the socket
	close(sockfd);
	close(connfd);
}

