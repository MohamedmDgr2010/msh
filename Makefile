SRC= main.cpp env.cpp excute.cpp
CXX= clang++
CXXFLAGS= -g -std=c++23 
all:
	$(CXX) $(SRC) $(CXXFLAGS) -o msh