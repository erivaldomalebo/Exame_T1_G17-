# Definir o compilador
CC = gcc

# Definir as flags de compilação
CFLAGS = -Wall -std=c99 -mconsole

# Lista de arquivos fonte
SRC = exame.c

# Nome do executável
OUT = programa

# Regra principal para compilar o projeto
all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@echo "✓ Compilação concluída com sucesso!"

# Regra para executar o programa após compilação
run: all
	@echo "Executando programa..."
	./$(OUT)

# Limpar os arquivos compilados (como o executável)
clean:
	rm -f $(OUT)
	@echo "✓ Executável removido!"

# Recompilar tudo do zero
rebuild: clean all

.PHONY: all run clean rebuild