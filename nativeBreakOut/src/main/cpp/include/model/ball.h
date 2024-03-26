#pragma once
#ifndef BALL_H
#define BALL_H

class Ball {
public:
    // Constructores
    Ball(float radius, float initialX, float initialY, float initialVelocityX, float initialVelocityY);
    Ball(); // Constructor por defecto

    // Métodos de acceso para obtener la posición y el radio de la bola
    float getX() const;
    float getY() const;
    float getRadius() const;

    // Métodos para establecer la posición de la bola
    void setPosition(float x, float y);

    // Método para cambiar la dirección de la bola cuando colisiona con un objeto
    void reverseVelocityX();
    void reverseVelocityY();

private:
    float m_X;            // Posición x de la bola
    float m_Y;            // Posición y de la bola
    float m_Radius;       // Radio de la bola
    float m_VelocityX;    // Velocidad horizontal de la bola
    float m_VelocityY;    // Velocidad vertical de la bola
};

#endif // BALL_H
