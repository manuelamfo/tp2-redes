// tipo da mensagem
typedef struct {
    // (1= telemetria , 2=ACK, 3=equipe de drones , 4= conclusao )
    uint16_t tipo;
    //tamanho do payload em bytes
    uint16_t tamanho;
} headert;

// telemetria
typedef struct {
    int id_cidade; // identificador do vértice
    int status; // 0 = OK, 1 = ALERTA
} telemetria_t;


// cliente -> servidor, envio de telemetria
typedef struct {
    int total; // número de cidades monitoradas
    telemetria_t dados [50]; // lista de (id_cidade, status)
} payload_telemetria_t;


// servidor -> cliente ou cliente -> servidor, confirmação de recebimento
typedef struct {
    int status; // 0=ACK_TELEMETRIA, 1=ACK_EQUIPE_DRONE, 2=ACK_CONCLUSAO
} payload_ack_t;

// servidor -> cliente, ordem de envio de drone
typedef struct {
    int id_cidade;
    int id_equipe;
} payload_equipe_drone_t;

// cliente -> servidor : conclusão de missão
typedef struct {
    int id_cidade;
    int id_equipe;
} payload_conclusao_t;

typedef struct {
    int id;
    char nome[100];
    int tipo; // 0 = cidade, 1 = capital
} vertice;

typedef struct {
    int destino;
    int distancia; // em km, é o peso da aresta 
    struct aresta* prox;
} aresta;

typedef struct {
    int num_vertices;
    vertice* array_vertices;
    aresta** lista_adj;
} grafo;
