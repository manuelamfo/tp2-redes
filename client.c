#include <stdio.h>
#include <string.h>
#include <stdint.h> // para usar uint16_t
#include <stdlib.h> // necessário para usar exit() e rand()
#include <unistd.h> // necessário para POSIX
#include <sys/socket.h> // necessário para a programação em sockets
#include <arpa/inet.h> // para a conversão de int. da representação de máquina para a representação da rede e vice-versa
#include <netinet/in.h> // para os tipos in_port_t e in_addr_t
#include <errno.h> // para mensagens de erro

typedef struct {
    // Tipo da mensagem
    // (1= telemetria , 2=ACK, 3=equipe de drones , 4= conclusao )
    uint16_t tipo;
    //tamanho do payload em bytes
    uint16_t tamanho;
} headert;

// Referências: https://idiotdeveloper.com/udp-client-server-implementation-in-c/ 
//https://www.geeksforgeeks.org/computer-networks/udp-client-server-using-connect-c-implementation/
// https://www.educative.io/answers/how-to-implement-udp-sockets-in-c
int main() {
    char buffer[100];
    char* client_message[2000], server_message[2000];
    int sockfd, n;
    struct sockaddr_in server_addr;
    int porta = 8080;

    // Limpa o server_addr
    memset(&server_addr, 0, sizeof(server_addr));

    // Cria o socket
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd < 0){
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");

    // Configuraa porta e o IP
    //! MUDAR PARA PERMITIR IPV6
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(porta);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter message: ");
    gets(client_message);
    
    // Envia a mensagem ao servidor
    int n = sendto(sockfd, client_message, strlen(client_message), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(n < 0){
        printf("Unable to send message\n");
        exit(-1);
    }

    // Recebe a mensagem de volta
    int r = recvfrom(sockfd, server_message, strlen(server_message), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (r < 0){
        printf("Error while receiving server's message\n");
        exit (-1);
    }
    
    printf("Server's response: %s\n", server_message);
    // Close the socket:
    close(sockfd);

    return 0;
}