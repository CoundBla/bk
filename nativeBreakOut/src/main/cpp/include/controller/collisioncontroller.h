#pragma once
#ifndef COLLISION_CONTROLLER_H
#define COLLISION_CONTROLLER_H

#include "../model/ball.h"
#include "../model/block.h"

class CollisionController {
public:
    // Constructor
    CollisionController(Paddle& paddle, Ball& ball, std::vector<Block>& blocks);

    // M�todo para detectar colisiones entre la bola y los bloques
    void detectCollisions();

private:
    // Referencia al objeto Paddle
    Paddle& paddle;

    // Referencia al objeto Ball
    Ball& ball;

    // Referencia al vector de bloques
    std::vector<Block>& blocks;

    // M�todos privados para detectar colisiones espec�ficas
    bool checkBallPaddleCollision();
    bool checkBallBlockCollision(const Block& block);
};

#endif // COLLISION_CONTROLLER_H
