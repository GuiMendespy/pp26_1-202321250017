# Nome do executável final
TARGET = debate_politico

# Compilador utilizado
CXX = g++

# Flags do compilador
# -Wall: Exibe todos os avisos (warnings)
# -std=c++11: Define o padrão C++11 (necessário para as funções de tempo/threads)
# -pthread: Necessário em sistemas Linux para suporte a threads
CXXFLAGS = -Wall -std=c++11 -pthread

# Lista de todos os arquivos de implementação (.cpp)
SRCS = main.cpp \
       logger.cpp \
       microfoneCronometro.cpp \
       configuracao.cpp \
       politicoColaborador.cpp \
       inquiridorColaborador.cpp \
       inquiridoColaborador.cpp \
       mediadorDebate.cpp \
       gerenciadorPolitico.cpp \
       facade.cpp

# Gera a lista de arquivos objeto (.o) substituindo a extensão .cpp de SRCS
OBJS = $(SRCS:.cpp=.o)

# Regra padrão (a primeira que o 'make' executa)
all: $(TARGET)

# Regra para ligar os arquivos objeto e criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra genérica para compilar cada arquivo .cpp em um .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos da compilação (objetos e executável)
clean:
	rm -f $(OBJS) $(TARGET)

# Regra para compilar e rodar o projeto automaticamente
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run