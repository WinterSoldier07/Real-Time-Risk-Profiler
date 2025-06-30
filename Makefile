CXX       = g++
CXXFLAGS  = -Iinclude -std=c++17 -O2

SRC       = src/main.cpp src/dea_model.cpp src/data_loader.cpp src/random_data.cpp
OBJ       = $(SRC:.cpp=.o)
EXEC      = risk_profiler

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) src/*.o