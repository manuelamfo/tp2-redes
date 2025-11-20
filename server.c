#include <stdio.h>
#include <string.h>
#include <stdint.h> // para usar uint16_t
#include <stdlib.h> // necessário para usar exit() e rand()
#include <unistd.h> // necessário para POSIX
#include <sys/socket.h> // necessário para a programação em sockets
#include <arpa/inet.h> // para a conversão de int. da representação de máquina para a representação da rede e vice-versa
#include <netinet/in.h> // para os tipos in_port_t e in_addr_t
#include <errno.h> // para mensagens de erro

#define PORT 8080

typedef struct {
    // Tipo da mensagem
    // (1= telemetria , 2=ACK, 3=equipe de drones , 4= conclusao )
    uint16_t tipo;
    //tamanho do payload em bytes
    uint16_t tamanho;
} headert;

// Referências: https://idiotdeveloper.com/udp-client-server-implementation-in-c/ 
//https://www.geeksforgeeks.org/computer-networks/udp-client-server-using-connect-c-implementation/
int main(int argc, char **argv){
    if (argc != 2) {
        printf("Coloque os argumentos na ordem certa!"); //! melhorar
        exit(0);
    }

    char* ip = "127.0.0.1"; //!!? conferir se é isso msm
    int porta = atoi(argv[1]);

    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char mensagem[1024];
    socklen_t addr_size;
    int n;

    //!! MODIFICAR PARA PERMITIR IPV6
    // Criação do socket UDP
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0){
        perror("[-]socket error");
        exit(1);
    }
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(porta);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // Junção do endereço do servidor com o socket
    n = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (n < 0){
        perror("[-]bind error");
        exit(1);
    }

    // Recebimento do datagrama enviado pelo cliente
    int len = sizeof(client_addr);

    return 0;
}