#pragma once
#ifndef BLOCK_H
#define BLOCK_H

class Block {
public:
    // Constructor
    Block(float x, float y, float width, float height, int initialHealth);
    Block(); // Constructor por defecto

    // M�todos de acceso para obtener la posici�n, dimensiones y salud del bloque
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    int getHealth() const;

    // M�todo para establecer la salud del bloque
    void setHealth(int health);

    // M�todo para reducir la salud del bloque
    void reduceHealth();

private:
    // Atributos del bloque
    float m_X;        // Posici�n x del bloque
    float m_Y;        // Posici�n y del bloque
    float m_Width;    // Ancho del bloque
    float m_Height;   // Altura del bloque
    int m_Health;     // Salud del bloque
};

#endif // BLOCK_H
