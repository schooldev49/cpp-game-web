all: 
	g++ -I src/include -L src/lib -o main src/main.cpp src/Engine.cpp src/TextureManager.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows


