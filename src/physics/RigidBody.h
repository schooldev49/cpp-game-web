#pragma once

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector2D.h"

#define UNI_MASS 1.0f
#define GRAVITY 9.8f

class RigidBody {
    public:
        RigidBody(){
            m_Mass = UNI_MASS;
            m_Gravity = GRAVITY;
        }
        inline void setMass(float mass){
            m_Mass = mass;
        }
        inline void setGravity(float grav){
            m_Gravity = grav;
        }

        inline void applyFriction(Vector2D frict){
            m_Friction = frict;
        }

        inline void defaultFriction(){
            m_Friction = Vector2D(0,0);
        }
        inline void applyForce(Vector2D force){
            m_Force = force; 
        }

        inline void applyForceX(float force){
            m_Force.X = force;
        }

        inline void applyForceY(float force){
            m_Force.Y = force;
        }
        inline void UnSetForce(){
            m_Force = Vector2D(0,0);
        }
        inline void defaultForce(){
            m_Force = Vector2D(0,0);
        }

        inline Vector2D Position(){
            return m_Position;
        }
        inline Vector2D Velocity(){
            return m_Velocity;
        }
        inline Vector2D Acceleration(){
            return m_Acceleration;
        }
        inline void Update(float dt){ // dt is calculus, derivatives/diffirential equations so i think its cool
            // f=ma 🤓🤓
            m_Acceleration.X = (m_Force.X + m_Friction.X)/m_Mass; 
            m_Acceleration.Y = (m_Gravity + m_Force.Y)/m_Mass;
            m_Velocity = m_Acceleration*dt;
            m_Position = m_Velocity * dt;
        }
    private:
        float m_Mass;
        float m_Gravity;
        Vector2D m_Force;
        Vector2D m_Friction;
        Vector2D m_Velocity;
        Vector2D m_Position;
        Vector2D m_Acceleration;

};

#endif