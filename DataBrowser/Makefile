# this is the gui makefile 
-include ../VERSION

ROOT_INCLUDE 	= $(shell  root-config  --incdir)
PRG_INCLUDE 	= ./include
PRG_SOURCE  	= ./source
#LIB_INCLUDE  	= /home/kabir/libNPDG/src/libNPDG  ####<===remove
LIB_INCLUDE	= /home/daq/NPDGamma/libNPDG/src ####<===add


OBJECTS       	= NPDGMain.o
DICTS	      	= $(OBJECTS:.o=Dict.o)
APPLIC        	= NPDGData$(VERS)

DEBUGFLAGS    	= #-DNPDG_DEBUG
CXX           	= g++
CXXFLAGS      	= -fPIC
LD            	= g++
LDFLAGS       	= -O2 -Wl,-rpath,$(LIB_INCLUDE)
SOFLAGS       	= -shared

ROOTCFLAGS   	:= $(shell root-config --cflags)
ROOTLIBS     	:= $(shell root-config --libs)
ROOTGLIBS    	:= $(shell root-config --glibs)

CXXFLAGS     	+= $(DEBUGFLAGS) $(ROOTCFLAGS)# -Wno-deprecated
LIBS          	= $(ROOTLIBS)
#GLIBS         	= $(ROOTGLIBS) -L/home/kabir/libNPDG/lib -lNPDG  ####<===remove
GLIBS         	= $(ROOTGLIBS) -L/home/daq/NPDGamma/libNPDG/lib -lNPDG  ####<===add



#-------------------------------------------------------

all:            $(APPLIC)


$(APPLIC):     	$(OBJECTS) $(DICTS)
		$(LD) $(LDFLAGS) $^ \
		-L/usr/X11R6/lib64 $(GLIBS) -lX11 -o $@	
	#	ln -sf NPDGData$(VERS) NPDGData
		@echo "$@ done"

%.o : $(PRG_SOURCE)/%.cxx
	$(CXX) -c $(CXXFLAGS) $< \
	-I$(ROOT_INCLUDE) -I$(PRG_INCLUDE) -I$(LIB_INCLUDE) 	

%Dict.o : %Dict.cxx
	$(CXX) -c $(CXXFLAGS) $< \
	-I$(ROOT_INCLUDE) -I$(PRG_INCLUDE) -I$(LIB_INCLUDE) 

%Dict.cxx : $(PRG_INCLUDE)/%.h #LinkDef.h
	@echo "Generating dictionary $@..."
	rootcint -f $@ -c $^

clean:
	rm -f ./*.o ./core ./*~ ./*Dict.cxx ./*Dict.h ./~* ./NPDGDataexported \
	./G__*.* source/*~ \
	include/*~
