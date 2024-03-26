#pragma once
#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
    // Constructor
    Paddle(float screenWidth, float screenHeight);
    Paddle(); // Constructor por defecto

    // Métodos de acceso para obtener la posición, ancho y alto de la paleta
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    float getScreenWidth() const;

    // Métodos para establecer la posición y dimensiones de la paleta
    void setPosition(float newX, float newY);
    void setSize(float newWidth, float newHeight);

    // Método para mover la paleta hacia la posición del toque en la pantalla
    void move(float touchX);

private:
    // Posición y dimensiones de la paleta
    float x, y; // Posición (esquina superior izquierda)
    float width, height; // Ancho y alto de la paleta

    // Dimensiones de la pantalla
    float screenWidth, screenHeight;

    // Velocidad de la paleta
    float velocityX;
};

#endif // PADDLE_H
