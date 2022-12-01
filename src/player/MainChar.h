#pragma once

#ifndef MAINCHAR_H
#define MAINCHAR_H

#include "Character.h"
#include "Animation.h"
#include "../physics/RigidBody.h"
#include "../graphics/TextureManager.h"
#include "../physics/Transform.h"
#include "../physics/CollisionHandler.h"
#include "../viewport/Viewport.h"
#include "../player/CharAnim.h"
#include "../physics/Collision.h"
#include "../input/Input.h"
class MainChar : public Character {

    public:
        MainChar(Properties* props);
        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);
    private:
        bool m_isJumping;
        bool m_isGrounded;

        float m_jumpTime;
        float m_jumpForce;

        Collision* m_Collider;
        Vector2D m_lastSafePosition;
        CharAnim* m_Animation;
        RigidBody* m_RigidBody;
    
};


#endif