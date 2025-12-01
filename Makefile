# Compilador e flags
CC = gcc
CFLAGS = -Wall -std=c99

# Diretórios
SRC_DIR = .
BIN_DIR = bin

# Arquivos fonte e destino
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_BIN = $(BIN_DIR)/client
SERVER_BIN = $(BIN_DIR)/server

# Regra padrão (executada com "make")
all: $(BIN_DIR) $(CLIENT_BIN) $(SERVER_BIN)

# Geração dos diretórios de saída
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compilação do cliente
$(CLIENT_BIN): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação do servidor
$(SERVER_BIN): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Limpeza dos binários gerados
clean:
	rm -rf $(BIN_DIR)

# Alvo para recompilar tudo do zero
rebuild: clean all