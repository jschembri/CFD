CXX=g++
CXXFLAGS=-Wall -g

analytical:
	$(CXX) $(CXXFLAGS) -c analytic.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o analytic analytic.o constants.o

answer:
	$(CXX) $(CXXFLAGS) -c answer.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o answer answer.o constants.o

upwind:
	$(CXX) $(CXXFLAGS) -c upwind.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o upwind upwind.o constants.o

make implicit:
	$(CXX) $(CXXFLAGS) -I /usr/local/include/eigen -c implicit.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o implicit implicit.o constants.o

make lax:
	$(CXX) $(CXXFLAGS) -c laxWendroff.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o laxWendroff laxWendroff.o constants.o

make rusanov:
	$(CXX) $(CXXFLAGS) -c rusanov.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o rusanov rusanov.o constants.o

all:
	$(CXX) $(CXXFLAGS) -c analytic.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o analytic analytic.o constants.o
	$(CXX) $(CXXFLAGS) -c upwind.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o upwind upwind.o constants.o
	$(CXX) $(CXXFLAGS) -I /usr/local/include/eigen -c implicit.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o implicit implicit.o constants.o
	$(CXX) $(CXXFLAGS) -c laxWendroff.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o laxWendroff laxWendroff.o constants.o
	$(CXX) $(CXXFLAGS) -c rusanov.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o rusanov rusanov.o constants.o
	$(CXX) $(CXXFLAGS) -c answer.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o answer answer.o constants.o

clean:
	rm analytic analytic.o upwind upwind.o implicit implicit.o laxWendroff laxWendroff.o rusanov rusanov.o answer answer.o

