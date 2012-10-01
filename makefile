CXX=g++
CXXFLAGS=-Wall -g

all:
	$(CXX) $(CXXFLAGS) -c main.cpp add.cpp
	$(CXX) $(CXXFLAGS) -o main main.o add.o


