# Nome dos executáveis
TARGET = app
LAUNCHER = launcher

# Compilador
CXX = g++

# Flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Todos os arquivos .cpp da pasta (exceto launcher.cpp)
SRCS = $(filter-out launcher.cpp, $(wildcard *.cpp))

# Arquivo do launcher
LAUNCHER_SRC = launcher.cpp

# Objetos
OBJS = $(SRCS:.cpp=.o)
LAUNCHER_OBJ = $(LAUNCHER_SRC:.cpp=.o)

# Regra principal
all: $(TARGET) $(LAUNCHER)

# Linkagem do app principal
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Linkagem do launcher
$(LAUNCHER): $(LAUNCHER_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilação
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar
clean:
	rm -f $(OBJS) $(LAUNCHER_OBJ) $(TARGET) $(LAUNCHER)

# Recompilar tudo
rebuild: clean all
