#Auther: Latiful Kabir
#Makefile for NPDG 24/7 DAQ watchdog program
#Date:09.08.14

CXX=g++
CFLAGS=-c 
LDFLAGS=
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/NPDGWatchdog
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	       $(CXX) $(LDFLAGS) $(OBJECTS) -o $@
%.o:%.cpp
	$(CXX) $(CFLAGS) $< -o $@

clear:
	rm -f src/*.o

clean:
	rm -f src/*.o $(EXECUTABLE)

