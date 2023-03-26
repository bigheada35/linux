#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>


#define PORT 8080


int main(void){
	printf("--hello test1\n");

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
 	time_t now = time(NULL);
	char *time_str_1 = ctime(&now);
	//struct tm *local_time = localtime(&now);
	//char time_str[20];	
	
   // Creating socket file descriptor
    printf("socket\n"); 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    printf("setsockopt\n"); 
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
	printf("bind\n");
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("listen\n");
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

	while(1){


    printf("accept\n");
   if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

	now = time(NULL);
   	time_str_1 = ctime(&now);
	printf("%s\n", time_str_1);
	//now = time(NULL);
	//local_time = localtime(&now);	
	//strftime(time_str, sizeof(time_str), "%H:%M:%S", local_time);
	//printf("%s\n", time_str);


//	while(1){

	printf("read\n");
    	valread = read( new_socket , buffer, 1024);
    	printf("%s\n",buffer );
	send(new_socket , hello , strlen(hello) , 0 );
	printf("Hello message sent\n");

	//}

	}

	return 0;
}
