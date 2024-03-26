#pragma once
#ifndef BALL_CONTROLLER_H
#define BALL_CONTROLLER_H

#include "../model/ball.h"

class BallController {
public:
    // Constructor
    BallController(Ball& ball);

    // Method to start the movement of the ball
    void startMovement();

    // Method to stop the movement of the ball
    void stopMovement();

    // Method to update the position of the ball
    void updateBallPosition(float deltaTime);

private:
    // Reference to the ball
    Ball& ball;

    // Ball velocity
    float velocityX;
    float velocityY;
};

#endif // BALL_CONTROLLER_H
