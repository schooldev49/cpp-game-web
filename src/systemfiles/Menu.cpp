#include "Menu.h"
#include "Engine.h"
#include "../input/Input.h"
#include <iostream>
Menu::Menu(){}

bool Menu::Init(std::string level){
    m_Ctxt = Engine::GetInstance()->GetRenderer();
    if (SDL_GetError()){
        std::cout << "Error! " << SDL_GetError() << "\n";
        return false;
    }
    return true;
}

bool Menu::Exit(){
    std::cout << "Exited." << "\n";
    return true;
}

void Menu::Render(){
    SDL_SetRenderDrawColor(m_Ctxt,16,45,70,255);
    SDL_RenderClear(m_Ctxt);
    SDL_RenderPresent(m_Ctxt);
}

void Menu::Update(){

}

void Menu::startGame(){

}

void Menu::settings(){

}

void Menu::levelSelector(){

}

void Menu::quit(){
    
}