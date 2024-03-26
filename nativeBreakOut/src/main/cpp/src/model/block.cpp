#include "../../include/model/block.h"

// Constructor con par�metros
Block::Block(float x, float y, float width, float height, int initialHealth)
    : m_X(x), m_Y(y), m_Width(width), m_Height(height), m_Health(initialHealth) {}

// Constructor por defecto (inicializa los valores a cero)
Block::Block() : m_X(0), m_Y(0), m_Width(0), m_Height(0), m_Health(0) {}

// M�todos de acceso para obtener la posici�n, dimensiones y salud del bloque
float Block::getX() const {
    return m_X;
}

float Block::getY() const {
    return m_Y;
}

float Block::getWidth() const {
    return m_Width;
}

float Block::getHeight() const {
    return m_Height;
}

int Block::getHealth() const {
    return m_Health;
}

// M�todo para establecer la salud del bloque
void Block::setHealth(int health) {
    m_Health = health;
}

// M�todo para reducir la salud del bloque
void Block::reduceHealth() {
    m_Health--;
}
