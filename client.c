#include<stdio.h>
#include<stdlib.h>

//definitions for socket functions and API to create sockets
#include<sys/types.h>
#include<sys/socket.h>

//to store address information under net_inet
#include<netinet/in.h>

int main(){

    //create a socket
    int network_socket;
    //domain, type-connection socket(tcp), explicitly specify the socket in case of raw sockets
    network_socket=socket(AF_INET, SOCK_STREAM, 0);

    //specify the address to connect to
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    //convert an u_short from host to network byte order(which is big endian)
    server_address.sin_port=htons(9002);
    //IP address
    //using shortcut
    //s.addr is a field holding the address(the real server address)
    server_address.sin_addr.s_addr=INADDR_ANY;

    //connect the socket(0-okay)
    //cast our server_address structure to a slightly different structure
    int connection_status=connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    //check for error with the connection
    if(connection_status==-1){
        printf("There was an error making a connection to the remote socket\n\n");
    }

    //receiving data
    //socket, place to hold the data we get back from the server, size
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response),0);

    //print the data we get back from the server
    printf("The server sent the data:%s", server_response);

    //close the socket
    close(network_socket);

    return 0;
}