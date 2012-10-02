CXX=g++
CXXFLAGS=-Wall -g

lax:
	$(CXX) $(CXXFLAGS) -c laxInviscid.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o laxInviscid laxInviscid.o constants.o

implicit:
	$(CXX) $(CXXFLAGS) -I /usr/local/include/eigen -c ImplicitInviscid.cpp constants.cpp
	$(CXX) $(CXXFLAGS) -o ImplicitInviscid ImplicitInviscid.o constants.o

