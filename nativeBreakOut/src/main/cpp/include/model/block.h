#pragma once
#ifndef BLOCK_H
#define BLOCK_H

class Block {
public:
    // Constructor
    Block(float x, float y, float width, float height, int initialHealth);
    Block(); // Constructor por defecto

    // Métodos de acceso para obtener la posición, dimensiones y salud del bloque
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    int getHealth() const;

    // Método para establecer la salud del bloque
    void setHealth(int health);

    // Método para reducir la salud del bloque
    void reduceHealth();

private:
    // Atributos del bloque
    float m_X;        // Posición x del bloque
    float m_Y;        // Posición y del bloque
    float m_Width;    // Ancho del bloque
    float m_Height;   // Altura del bloque
    int m_Health;     // Salud del bloque
};

#endif // BLOCK_H
