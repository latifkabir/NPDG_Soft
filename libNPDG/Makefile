#Makefile for compiling n3He library
#Update and Modified By: Latiful Kabir
#Date: 12/25/14
ROOTCINT  = rootcint
ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --glibs)
CXXFLAGS  += -fPIC

all: libNPDG

clean: libNPDG_clean
clear: libNPDG_clear

# BEGIN libNPDG

libNPDG: lib/libNPDG.so
libNPDG_base	= TBranchBinary TTreeRaw ReadBinary CalOffset

libNPDG_inc	= $(libNPDG_base:=.h)
libNPDG_obj	= $(addprefix src/,$(libNPDG_base:=.o))

lib/libNPDG.so: $(libNPDG_obj) src/libNPDG_Dict.o
	$(CXX) -o $@ $(CXXFLAGS) -shared -Wl,-soname,libNPDG.so $^

src/%.o: src/%.cc
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) $(ROOTFLAGS) $<

src/libNPDG_Dict.cc:
	cd src/; $(ROOTCINT) -f libNPDG_Dict.cc -c $(libNPDG_inc) LinkDef.h

libNPDG_clean:
	rm -f $(libNPDG_obj)
	rm -f src/*_Dict.*
	rm -f lib/libNPDG.so

libNPDG_clear:
	rm -f $(libNPDG_obj)
	rm -f src/*_Dict.*


