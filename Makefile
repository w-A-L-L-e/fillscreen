LIBS=`sdl2-config --libs`
# LIBS=`sdl2-config --static-libs`
# STATIC (/usr/local/lib/libSDL2main.a for windows might be needed)
CPPFLAGS=-I.
OBJECTS=screen.o main.o 
EXECUTABLES=fillscreen
all: $(EXECUTABLES)

# work in progress
#world_engine: $(ENGINE_OBJECTS) world_engine.o
#	$(CXX) -O2 $^ -o world_engine -Iinclude $(LIBS)

fillscreen: $(OBJECTS)
	$(CXX) -O2 $^ -o fillscreen -Iinclude $(LIBS)

install: $(EXECUTABLES)
	cp $(EXECUTABLES) ~/bin

clean:
	@rm -vf *.o $(EXECUTABLES)

