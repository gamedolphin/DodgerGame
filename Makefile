#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

BGFX_HEADERS =  -Ilibs/bgfx/include -Ilibs/bx/include -Ilibs/bimg/include
BGFX_LDDEPS = libs/libbgfx-shared-libRelease.so

HEADER_FLAGS = -Iwindow/ -Icore/ -Irenderer/ -Ievents/ -Igame/
#OBJS specifies which files to compile as part of the project
OBJS = main.cpp events/events.h

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = $(BGFX_LDDEPS) -lSDL2 -lGL -lX11 -ldl -lpthread -lrt

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

COMPONENTS = window.o renderer.o game.o fileio.o

renderer.o : renderer/renderer_linux.cpp core/app_mem.h renderer/renderer_common.cpp
	$(CC) -c renderer/renderer_linux.cpp  $(BGFX_HEADERS) -o renderer.o

window.o : window/window_linux.cpp core/app_mem.h
	$(CC) -c window/window_linux.cpp -o window.o

fileio.o : fileio/fileio_linux.cpp
	$(CC) -c fileio/fileio_linux.cpp -o fileio.o

game.o : game/game_linux.cpp core/app_mem.h
	$(CC) -c game/game_linux.cpp -o game.o

#This is the target that compiles our executable
all : $(OBJS) $(COMPONENTS)
	$(CC) \
	-DDEBUG \
	-o $(OBJ_NAME) \
	$(COMPONENTS) $(OBJS) \
	$(HEADER_FLAGS) $(COMPILER_FLAGS) $(LINKER_FLAGS)

clean :
	rm $(COMPONENTS) main
