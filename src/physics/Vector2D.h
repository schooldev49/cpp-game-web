#pragma once

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
    public: 
        float X, Y = 0;
        Vector2D(float x=0, float y=0): X(x), Y(y) {}
        inline Vector2D operator+(const Vector2D& v2) const {
            return Vector2D(X + v2.X, Y + v2.Y);
        }
        inline Vector2D operator-(const Vector2D& v2) const {
            return Vector2D(X - v2.X, Y - v2.Y);
        }
        inline Vector2D operator*(const float scalar) const {
            return Vector2D(X * scalar, Y * scalar);
        }
    private: 
};

#endif