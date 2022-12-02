#include "MainChar.h"
#include <stdlib.h>
#include <SDL2/SDL.h>

#include <iostream>
MainChar::MainChar(Properties* props): Character(props) {
    m_jumpTime = 15.0f;
    m_jumpForce = 15.0f;

    m_Collider = new Collision();

    m_Collider->SetBuffer(40,45,0,0);

    m_RigidBody = new RigidBody();
    m_RigidBody->setGravity(3.25f);
    m_Animation = new CharAnim();
    
    std::cout << "anima..";
    
    m_Animation->SetProps(m_TextureID,1,7,100);
    std::cout << "done anime";
}

void MainChar::Draw(){
    if (!m_Transform->Y || m_Transform->Y >= 5000){ // it's a crash bound to happen sometime - fallback
        m_Transform->Y = 200; // moves to default pos;
    }
    if (m_Transform->Y >= 510){
        
        std::cout << "\nYou Lost at " << m_Transform->Y << "!\n";
        Engine::GetInstance()->setRunning(false);
        return;
    } else { 
        m_Animation->Draw(m_Transform->X, m_Transform->Y,m_width,m_height,1,1,m_Flip);

        m_Collider->Draw();
    }
}

void MainChar::Update(float dt){
    
    m_Animation->SetProps("player",1,7,100);
    m_RigidBody->UnSetForce();
    if (Input::GetInstance()->getKeyDown(SDL_SCANCODE_A)){
       // m_Animation->SetProps("player_run",1,8,80);
        m_RigidBody->applyForceX(-5);
    } 
    if (Input::GetInstance()->getKeyDown(SDL_SCANCODE_D)){
        //m_Animation->SetProps("player_run",1,8,80,SDL_FLIP_HORIZONTAL);
        m_RigidBody->applyForceX(5);
    }

    if (Input::GetInstance()->getKeyDown(SDL_SCANCODE_SPACE) && m_isGrounded){
        m_isJumping = true;
        m_isGrounded = false;
        m_RigidBody->applyForceY(-1*m_jumpForce);
    }

    if (Input::GetInstance()->getKeyDown(SDL_SCANCODE_SPACE) && m_isJumping && m_jumpTime > 0){
        m_jumpTime -= dt;
        m_RigidBody->applyForceY(-0.75f*m_jumpForce);
    } else {
        m_isJumping = false;
        m_jumpTime = 15.0f;
    }
    m_RigidBody->Update(dt); 

    m_lastSafePosition.X = m_Transform->X;
    m_Transform->X += m_RigidBody->Position().X;
    m_Collider->Set(m_Transform->X, m_Transform->Y, 40,78);

    if (CollisionHandler::GetInstance()->MapCollision(m_Collider->Get())){
        m_Transform->X = m_lastSafePosition.X;
    }

    m_RigidBody->Update(dt);
    m_lastSafePosition.Y = m_Transform->Y;
    m_Transform->Y += m_RigidBody->Position().Y;
    m_Collider->Set(m_Transform->X,m_Transform->Y,40,78);

    if (CollisionHandler::GetInstance()->MapCollision(m_Collider->Get())){
        m_isGrounded = true;
        m_Transform->Y = m_lastSafePosition.Y;
    } else {
        m_isGrounded = false;
    }

    m_Origin->X = m_Transform->X + m_width/2;
    m_Origin->Y = m_Transform->Y + m_height/2;

   // m_Transform->TranslateY(m_RigidBody->Position().Y);


    m_Animation->Update(dt);
}

void MainChar::Clean(){
    TextureManager::GetInstance()->Drop(m_TextureID);
}