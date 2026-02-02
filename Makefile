# Definir o compilador
CC = gcc

# Definir as flags de compilação
CFLAGS = -Isrc/include -Wall -std=c99 -finput-charset=UTF-8 -fexec-charset=UTF-8

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Lista de arquivos fonte
SOURCES = $(SRC_DIR)/main.c \
          $(SRC_DIR)/cliente.c \
          $(SRC_DIR)/caixa.c

# Lista de arquivos objeto
OBJECTS = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/cliente.o

# Nome do executável
TARGET = $(BIN_DIR)/programa

# Criar diretórios se não existirem
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Regra principal
all: $(TARGET)

# Compilar o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)
	@echo "✓ Compilação concluída com sucesso!"

# Compilar cada arquivo .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para executar o programa
run: all
	@echo "Executando programa..."
	@./$(TARGET)

# Limpar arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "✓ Arquivos compilados removidos!"

# Recompilar tudo do zero
rebuild: clean all

.PHONY: all run clean rebuild
