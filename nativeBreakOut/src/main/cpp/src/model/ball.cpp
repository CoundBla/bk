#include "../../include/model/ball.h"

// Constructor con par�metros
Ball::Ball(float radius, float initialX, float initialY, float initialVelocityX, float initialVelocityY)
    : m_Radius(radius), m_X(initialX), m_Y(initialY), m_VelocityX(initialVelocityX), m_VelocityY(initialVelocityY) {}

// Constructor por defecto (inicializa los valores a cero)
Ball::Ball() : m_Radius(0), m_X(0), m_Y(0), m_VelocityX(0), m_VelocityY(0) {}

// M�todos de acceso para obtener la posici�n y el radio de la bola
float Ball::getX() const {
    return m_X;
}

float Ball::getY() const {
    return m_Y;
}

float Ball::getRadius() const {
    return m_Radius;
}

// M�todos para establecer la posici�n de la bola
void Ball::setPosition(float x, float y) {
    m_X = x;
    m_Y = y;
}

// M�todo para cambiar la direcci�n de la bola cuando colisiona con un objeto
void Ball::reverseVelocityX() {
    m_VelocityX = -m_VelocityX;
}

void Ball::reverseVelocityY() {
    m_VelocityY = -m_VelocityY;
}
