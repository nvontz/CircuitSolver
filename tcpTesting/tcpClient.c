#include <netdb.h>
#include <unistd.h> // for read, write, close, etc
#include <arpa/inet.h> // for inet_addr
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> //sockaddr
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int sockfd)
{
	char buff[MAX];
	int n;
	for (;;) {
		bzero(buff, sizeof(buff));
		printf("Enter the string : ");
		n = 0;
		while ((buff[n++] = getchar()) != '\n');

		write(sockfd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));

		read(sockfd, buff, sizeof(buff));
		printf("From Server : %s", buff);

		if ((strncmp(buff, "exit", 4)) == 0) {
			printf("Client Exit...\n");
			break;
		}
	}
}

int main()
{
	/* socket file descriptor and connection file descriptor */
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// create socket 
	// AF_INET: address family, accepts IPv4
	// SOCK_STREAM: TCP 
	// 0 refers to the default protocol, as SOCK_STREAM identifies TCP
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// Family of IP versions, IPv4
	servaddr.sin_family = AF_INET;

	// from my testing, this is the IP addr of the server to connect this client to
	servaddr.sin_addr.s_addr = inet_addr("10.150.114.142"); 
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");

	// function for chat
	func(sockfd);

	// close the socket
	close(sockfd);
}

