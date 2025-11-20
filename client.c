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