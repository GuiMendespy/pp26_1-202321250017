# Variáveis de Configuração
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I.

# Nome do executável final
TARGET = programa_debate

# Procura automaticamente por todos os arquivos .cpp na pasta atual
SRCS = $(wildcard *.cpp)

# Define os arquivos .o correspondentes para cada .cpp encontrado
OBJS = $(SRCS:.cpp=.o)

# Regra principal (padrão): Compila o programa inteiro
all: $(TARGET)

# Linkagem: Junta todos os arquivos .o para gerar o executável final
$(TARGET): $(OBJS)
	@echo "Linkando os objetos e gerando o executável: $(TARGET)..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compilação: Transforma cada arquivo .cpp individual em um .o
%.o: %.cpp
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para compilar e EXECUTAR logo em seguida
run: all
	@echo "Executando o programa..."
	@echo "------------------------------------------"
	./$(TARGET)

# Limpeza: Apaga o executável e todos os arquivos .o gerados
clean:
	@echo "Limpando arquivos temporários e executável..."
	rm -f $(OBJS) $(TARGET)

# Declara regras fictícias (evita conflito se houver arquivos chamados 'run' ou 'clean')
.PHONY: all run clean