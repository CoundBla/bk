#include "../../include/controller/BallController.h"

BallController::BallController(Ball& ball) : ball(ball), velocityX(0.0f), velocityY(0.0f) {}

void BallController::startMovement() {
    // Start the movement of the ball
    // For example, set an initial velocity
    velocityX = 10.0f; // Initial velocity in X
    velocityY = 10.0f; // Initial velocity in Y
}

void BallController::stopMovement() {
    // Stop the movement of the ball
    // For example, set velocities to zero
    velocityX = 0.0f;
    velocityY = 0.0f;
}

void BallController::updateBallPosition(float deltaTime) {
    // Update the position of the ball based on delta time
    // Velocity and delta time are used to calculate displacement
    float displacementX = velocityX * deltaTime;
    float displacementY = velocityY * deltaTime;

    // Update the position of the ball
    float newX = ball.getX() + displacementX;
    float newY = ball.getY() + displacementY;
    ball.setPosition(newX, newY);
}
