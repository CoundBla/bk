#pragma once
#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
    // Constructor
    Paddle(float screenWidth, float screenHeight);
    Paddle(); // Constructor por defecto

    // M�todos de acceso para obtener la posici�n, ancho y alto de la paleta
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    float getScreenWidth() const;

    // M�todos para establecer la posici�n y dimensiones de la paleta
    void setPosition(float newX, float newY);
    void setSize(float newWidth, float newHeight);

    // M�todo para mover la paleta hacia la posici�n del toque en la pantalla
    void move(float touchX);

private:
    // Posici�n y dimensiones de la paleta
    float x, y; // Posici�n (esquina superior izquierda)
    float width, height; // Ancho y alto de la paleta

    // Dimensiones de la pantalla
    float screenWidth, screenHeight;

    // Velocidad de la paleta
    float velocityX;
};

#endif // PADDLE_H
