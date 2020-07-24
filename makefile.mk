# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

/bin/main: /src/main.o /src/PathFind_Chernobyl.o 
	$(CXX) $(CXXFLAGS) -o main /src/main.o /src/PathFind_Chernobyl.o

# The main.o target can be written more simply

/src/main.o: /src/main.cpp /include/PathFind_Chernobyl.h /src/PathFind_Chernobyl.cpp
	$(CXX) $(CXXFLAGS) -c /src/main.cpp

/src/PathFind_Chernobyl.o: /src/PathFind_Chernobyl.cpp /include/PathFind_Chernobyl.h 
	$(CXX) $(CXXFLAGS) -c /src/PathFind_Chernobyl.cpp
