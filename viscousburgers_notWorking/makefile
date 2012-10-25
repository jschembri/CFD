CXX=g++
CXXFLAGS=-Wall -g

answer:
	$(CXX) $(CXXFLAGS) -c answer.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o answer answer.o constants.o

explicit:
	$(CXX) $(CXXFLAGS) -c explicit.cpp explicit.cpp
	$(CXX) $(CXXFLAGS) -o explicit explicit.o constants.o

implicit:
	$(CXX) $(CXXFLAGS) -I /usr/local/include/eigen -c implicit.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o implicit implicit.o constants.o

clean:
	rm explicit explicit.o

FTCS:
	$(CXX) $(CXXFLAGS) -c FTCS.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o FTCS FTCS.o constants.o

Mac:
	$(CXX) $(CXXFLAGS) -c MacCormack.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o MacCormack MacCormack.o constants.o


