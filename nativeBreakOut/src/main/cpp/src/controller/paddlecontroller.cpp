#include "../../include/controller/paddlecontroller.h"

PaddleController::PaddleController(Paddle& paddle) : paddle(paddle) {}


void PaddleController::movePaddle(int touchX, int touchY) {
    // Ajustar la posici�n de la paleta seg�n la entrada t�ctil
    int paddleWidth = paddle.getWidth();
    int screenWidth = paddle.getScreenWidth();

    // Asegurarse de que el toque est� dentro de los l�mites de la pantalla
    if (touchX < 0) {
        touchX = 0;
    }
    else if (touchX > screenWidth - paddleWidth) {
        touchX = screenWidth - paddleWidth;
    }

    // Establecer la nueva posici�n de la paleta
    paddle.setPosition(touchX, paddle.getY());
}
