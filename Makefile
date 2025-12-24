CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/Histogram.cpp src/AlphabetIndex.cpp src/Search.cpp src/Tests.cpp
OBJ = $(SRC:.cpp=.o)

all: lab2

lab2: $(OBJ) main.o
	$(CXX) $(CXXFLAGS) $(OBJ) main.o -o lab2

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f src/*.o *.o lab2