# Makefile for wave_test

# FLUID file rules:
TARGETS = play
TABS_OBJ = play.o
WAVEFILE_OBJ = wav_file.o

# compiler names:
CXX		= arm-linux-g++
STRIP	= arm-linux-strip

# flags for C++ compiler:
OPTIM		= -O2 -Wall -Wunused -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp
CXXFLAGS	= $(OPTIM) `pkg-config --cflags x11 freetype2` -I${CROSS_ENV}/usr/src/linux/include
#-I../../fltk-2-0-x -I../../libemt -I../

# libraries to link with:
LDLIBS		=  `pkg-config  --libs x11` -Wl,-rpath,${CROSS_ENV}/usr/lib/ -lXi -lXrender -lexpat -lfreetype -lfontconfig -lXft -lXext -lXpm -lcryptopp -L../../sysutil -l confuse -lpthread -lm -lsupc++ -lasound
LINKEMT		= -L../../libemt -leMT
LINKFLTK	= -L../../fltk-2-0-x/lib -lfltk

# Make everything...
all: $(TARGETS)

$(TARGETS): $(TABS_OBJ) $(WAVEFILE_OBJ)
	$(CXX) -o $@ $(TABS_OBJ) $(WAVEFILE_OBJ) -I. $(LINKEMT) $(LINKFLTK) $(LDLIBS)
	$(STRIP) $@

play.o: play.cxx
	$(CXX) -I. $(CXXFLAGS) -c $<

wav_file.o: wav_file.cxx wav_file.h
	$(CXX) -I. $(CXXFLAGS) -c $<


# Clean old files...
clean:
	rm -f *.o *~ $(TARGETS)
