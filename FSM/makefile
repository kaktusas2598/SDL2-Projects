#Which file to compile
OBJS = main.cpp Game.cpp GameState.cpp MenuState.cpp PlayState.cpp InputHandler.cpp TextureManager.cpp SDLGameObject.cpp Player.cpp Enemy.cpp

#Compiler used
CC = g++

#Additional compilation options
# -w suppresses all warnings
# -g generate debugging info
COMPILER_FLAGS = -w

#Libraries we're linking ag we're usingainst
LINKER_FLAGS = -lSDL2 -lSDL2_image

#Name of executable
OBJ_NAME = main

#Target to compile executable
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
