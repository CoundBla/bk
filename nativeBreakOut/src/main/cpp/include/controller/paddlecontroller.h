#pragma once
#ifndef PADDLE_CONTROLLER_H
#define PADDLE_CONTROLLER_H

#include "../model/paddle.h"

class PaddleController {
public:
    // Constructores
    PaddleController(Paddle& paddle);
    PaddleController(); // Constructor por defecto

    // M�todo para manejar el movimiento de la paleta
    void movePaddle(int touchX);

private:
    // Referencia a la paleta
    Paddle& paddle;
};

#endif // PADDLE_CONTROLLER_H
