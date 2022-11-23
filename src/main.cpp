#include <iostream>
#include <cstdio>
/*#include "../emsdk/upstream/emscripten/system/include/emscripten.h"*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "systemfiles/Engine.h"
#include "graphics/TextureManager.h"

const unsigned int WIDTH = 800, HEIGHT = 600;

int main(int argc, char* argv[]){
    
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0){
        std::cout << "success!";
    } else {
        std::cout << "there is an error: " << SDL_GetError() << "\n";
        return EXIT_FAILURE;
    };

    static Engine* engine = Engine::GetInstance();

    engine->Init();

    while (engine->isRunning()){
        engine->Events(); 
        engine->Update();
        engine->Render();

    }
    engine->Clean();
    return 0;
   /* SDL_Window *window = SDL_CreateWindow("Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL){
        std::cout << "Could not create window! Erorr " << SDL_GetError() << "\n"; 
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,0);

    SDL_Event windowEvent; 
    while(true){
        if (SDL_PollEvent(&windowEvent)){
            if (windowEvent.type == SDL_QUIT){
                break;
            }
            if (SDL_MOUSEMOTION == windowEvent.type){
                int x, y;
                SDL_GetMouseState(&x,&y);

            }
            if (SDL_MOUSEBUTTONDOWN == windowEvent.type){
                if (SDL_BUTTON_LEFT == windowEvent.button.button){
                    changeColor(renderer,26,100,105,0.8);

                }
            } 
            if (SDL_KEYDOWN == windowEvent.type){
               if (SDLK_w == windowEvent.key.keysym.sym){
                  changeColor(renderer,86,194,145,0.8);

               } else if (SDLK_a == windowEvent.key.keysym.sym){
                  changeColor(renderer,86,100,145,0.8);
               }
               else if (SDLK_s == windowEvent.key.keysym.sym){
                  changeColor(renderer,96,100,145,0.8);
               } else if (SDLK_d == windowEvent.key.keysym.sym){
                  changeColor(renderer,56,100,145,0.8);
               }

            } else if (SDL_KEYDOWN == windowEvent.type){
                std::cout << "key up" << "\n";
                changeColor(renderer,86,194,145,0.8);
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;*/
}

// emscripten_set_main_loop