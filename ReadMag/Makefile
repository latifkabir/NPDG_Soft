#Auther: Latiful Kabir
#Makefile for reading magnetic field
#Date:02.02.15

CXX=g++
CFLAGS=-c 
LDFLAGS= -lncurses
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/magField
all:$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	       $(CXX)  $(OBJECTS) $(LDFLAGS) -o $@
%.o:%.cpp
	$(CXX) $(CFLAGS)  $< $(LDFLAGS) -o $@

clear:
	rm -f src/*.o

clean:
	rm -f src/*.o $(EXECUTABLE)

