emcc src/main.cpp -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=3 -s SDL2_IMAGE_FORMATS='["png","jpg"]' --preload-file res -o test/index.js
