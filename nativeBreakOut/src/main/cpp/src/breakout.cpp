#include "breakout.h"
#include "paddle.h"
#include "ball.h"
#include <iostream>


// Constructor
Breakout::Breakout(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight), score(0), lives(3), paddle(screenWidth, screenHeight), ball(screenWidth, screenHeight) {
    // Initialize bricks
    initializeBricks();
    // Initialize ball
    initializeBall();
}

// Destructor
Breakout::~Breakout() {
    // No specific cleanup actions needed
}

// Update function - called once per frame
void Breakout::update() {
    // Update game logic
    moveBall();
    checkCollisions();
    updateScoreAndLives();
}

// Render function - called once per frame to render game elements
void Breakout::render() {
    // Render game elements on the screen
    renderPaddle();
    renderBricks();
    renderBall();
}

// Function to move the paddle
void Breakout::movePaddle(int direction) {
    // Move the paddle in the specified direction
    paddle.move(direction);
}

// Function to check collisions between game elements
void Breakout::checkCollisions() {
    // Check collisions between ball, paddle, and bricks
    // Ball-paddle collision
    if (ball.intersects(paddle)) {
        ball.bounceOffPaddle();
    }
    // Ball-brick collisions
    for (auto& brick : bricks) {
        if (brick.isVisible() && ball.intersects(brick)) {
            brick.setVisibility(false);
            ball.bounceOffBrick();
            increaseScore();
        }
    }
    // Ball-wall collisions
    if (ball.hitsTopWall() || ball.hitsSideWalls()) {
        ball.bounceOffWall();
    }
    // Ball-bottom wall collision (loss of life)
    if (ball.hitsBottomWall()) {
        decreaseLives();
        resetBallAndPaddle();
    }
}

// Function to initialize bricks
void Breakout::initializeBricks() {
    // Initialize game bricks
    // This could include creating a specific pattern of bricks on the screen
    // and setting their positions, colors, etc.
}

// Function to initialize the ball
void Breakout::initializeBall() {
    // Initialize game ball
    // This could include setting initial position, initial velocity, etc.
}

// Function to move the ball
void Breakout::moveBall() {
    // Move the ball based on its current speed and direction
    ball.move();
}

// Function to update score and lives
void Breakout::updateScoreAndLives() {
    // Update player score and lives
    // This could include displaying score and lives on the game UI
    // For now, let's just print them to the console
    std::cout << "Score: " << score << " Lives: " << lives << std::endl;
}

// Function to render the paddle
void Breakout::renderPaddle() {
    // Render the paddle on the screen
}

// Function to render the bricks
void Breakout::renderBricks() {
    // Render the bricks on the screen
}

// Function to render the ball
void Breakout::renderBall() {
    // Render the ball on the screen
}

// Function to increase player score
void Breakout::increaseScore() {
    // Increment player score
}

// Function to decrease player lives
void Breakout::decreaseLives() {
    // Decrement player lives
    lives--;
    // Check for game over condition
    if (lives <= 0) {
        std::cout << "Game Over!" << std::endl;
        // Add logic to display game over screen and options
    }
}

// Function to reset ball and paddle positions
void Breakout::resetBallAndPaddle() {
    // Reset ball and paddle positions to initial positions
}