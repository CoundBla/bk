#include "../../include/model/paddle.h"

// Constructor con par�metros
Paddle::Paddle(float screenWidth, float screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight), velocityX(0.0f) {
    // Inicializar la posici�n y dimensiones de la paleta
    x = screenWidth / 2; // Centrar la paleta horizontalmente
    y = screenHeight - 50; // Colocar la paleta cerca de la parte inferior de la pantalla
    width = 100; // Ancho predeterminado de la paleta
    height = 20; // Altura predeterminada de la paleta
}

// Constructor por defecto (inicializa los valores a cero)
Paddle::Paddle() : width(800), height(600), x(0), y(0) {}

// M�todos de acceso para obtener la posici�n, ancho y alto de la paleta
float Paddle::getX() const {
    return x;
}

float Paddle::getY() const {
    return y;
}

float Paddle::getWidth() const {
    return width;
}

float Paddle::getHeight() const {
    return height;
}

float Paddle::getScreenWidth() const {
    return screenWidth;
}

// M�todos para establecer la posici�n y dimensiones de la paleta
void Paddle::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

void Paddle::setSize(float newWidth, float newHeight) {
    width = newWidth;
    height = newHeight;
}

// M�todo para mover la paleta hacia la posici�n del toque en la pantalla
void Paddle::move(float touchX) {
    // Mover la paleta hacia la posici�n del toque en la pantalla
    float paddleCenterX = x + width / 2;
    float touchOffset = touchX - paddleCenterX;
    x += touchOffset;

    // Asegurar que la paleta permanezca dentro de los l�mites de la pantalla
    if (x < 0) {
        x = 0;
    }
    else if (x + width > screenWidth) {
        x = screenWidth - width;
    }
}
