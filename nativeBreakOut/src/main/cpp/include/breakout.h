#pragma once
#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "model/paddle.h"
#include "model/ball.h"
#include "model/block.h"

class Breakout {
public:
    Breakout(int screenWidth, int screenHeight);
    void update(); // Function to update game state
    void render(); // Function to render game graphics

private:
    int screenWidth;
    int screenHeight;
    int score;
    int lives;
    Paddle paddle;
    Ball ball;
    // Declaration of function to initialize bricks
    void initializeBricks();
    // Other member functions
    void checkCollisions(); // Function to check collisions
    void updatePaddle(); // Function to update paddle
    void updateBall(); // Function to update ball
    void updateBricks(); // Function to update bricks
    void checkGameOver(); // Function to check game over condition
};

#endif
