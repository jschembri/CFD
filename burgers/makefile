CXX=g++
CXXFLAGS=-Wall -g

lax:
	$(CXX) $(CXXFLAGS) -c laxInviscid.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o laxInviscid laxInviscid.o constants.o

implicit:
	$(CXX) $(CXXFLAGS) -I /usr/local/include/eigen -c ImplicitInviscid.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o ImplicitInviscid ImplicitInviscid.o constants.o

answer:
	$(CXX) $(CXXFLAGS) -I /usr/local/include/eigen -c answer.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o answer answer.o constants.o

Wendroff-Lax:
	$(CXX) $(CXXFLAGS) -c laxWendroff.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o laxWendroff laxWendroff.o constants.o
