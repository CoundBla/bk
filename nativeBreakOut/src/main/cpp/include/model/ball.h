#pragma once
#ifndef BALL_H
#define BALL_H

class Ball {
public:
    // Constructores
    Ball(float radius, float initialX, float initialY, float initialVelocityX, float initialVelocityY);
    Ball(); // Constructor por defecto

    // M�todos de acceso para obtener la posici�n y el radio de la bola
    float getX() const;
    float getY() const;
    float getRadius() const;

    // M�todos para establecer la posici�n de la bola
    void setPosition(float x, float y);

    // M�todo para cambiar la direcci�n de la bola cuando colisiona con un objeto
    void reverseVelocityX();
    void reverseVelocityY();

private:
    float m_X;            // Posici�n x de la bola
    float m_Y;            // Posici�n y de la bola
    float m_Radius;       // Radio de la bola
    float m_VelocityX;    // Velocidad horizontal de la bola
    float m_VelocityY;    // Velocidad vertical de la bola
};

#endif // BALL_H
