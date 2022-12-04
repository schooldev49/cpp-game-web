#pragma once 

#ifndef MENU_H
#define MENU_H
#include <SDL2/SDL.h>
#include "GameState.h"
class Menu : public GameState {
    public:
        Menu();
        virtual bool Init(std::string level = "level1");
        virtual bool Exit();
        virtual void Update();
        virtual void Render();

    protected:
        static void startGame();
        static void settings();
        static void levelSelector();
        static void quit();
};

#endif