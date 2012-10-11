CXX=g++
CXXFLAGS=-Wall -g

analytical:
	$(CXX) $(CXXFLAGS) -c analytic.cpp 
	$(CXX) $(CXXFLAGS) -o analytic analytic.o

upwind:
	$(CXX) $(CXXFLAGS) -c upwind.cpp 
	$(CXX) $(CXXFLAGS) -o upwind upwind.o

make implicit:
	$(CXX) $(CXXFLAGS) -I /usr/local/include/eigen -c implicit.cpp 
	$(CXX) $(CXXFLAGS) -o implicit implicit.o

make lax:
	$(CXX) $(CXXFLAGS) -c laxWendroff.cpp 
	$(CXX) $(CXXFLAGS) -o laxWendroff laxWendroff.o

make rusanov:
	$(CXX) $(CXXFLAGS) -c rusanov.cpp 
	$(CXX) $(CXXFLAGS) -o rusanov rusanov.o


clean:
	rm analytic analytic.o upwind upwind.o implicit implicit.o lax lax.o rusanov rusanov.o

