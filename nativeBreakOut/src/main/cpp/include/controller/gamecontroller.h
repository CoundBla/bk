#pragma once
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "../model/game.h"
#include "paddlecontroller.h"
#include "collisioncontroller.h"
#include "ballcontroller.h"

class GameController {
public:
    // Constructor
    GameController(Game& game);

    // M�todos para manejar la entrada del jugador
    void handleInput(int touchX);

    // M�todo para actualizar el estado del juego
    void updateGame(float deltaTime);

    // M�todo para manejar el fin del juego
    void handleGameOver();

    // M�todo para pausar el juego
    void pauseGame();

    // M�todo para reanudar el juego
    void resumeGame();

private:
    // Referencia al objeto Game
    Game& game;

    // Controladores del juego
    PaddleController paddleController;
    BallController ballController;
    CollisionController collisionController;
};

#endif // GAME_CONTROLLER_H
