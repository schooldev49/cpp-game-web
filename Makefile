all: 
	g++ -I src/include -L src/lib -o main src/main.cpp src/graphics/TextureManager.cpp src/systemfiles/Engine.cpp src/player/MainChar.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows


