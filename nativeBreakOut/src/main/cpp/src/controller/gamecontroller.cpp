#include "../../include/controller/gamecontroller.h"

// Constructor
GameController::GameController(Game& game)
    : game(game),
    paddleController(game.getPaddle()),
    ballController(game.getBall()),
    collisionController(game.getPaddle(), game.getBall(), game.getBlocks()) {}

// handles player input
void GameController::handleInput(int touchX int touchY) {
    if (!game.isPaused()) {
        paddleController.movePaddle(touchX);
    }
}

// updates the game
void GameController::updateGame(float deltaTime) {
    if (!game.isPaused()) {
        ballController.updateBallPosition(deltaTime);
        collisionController.detectCollisions();
    }
}

// handle game over
void GameController::handleGameOver() {
    if (game.isGameOver()) {
        // game is over,
    }
}

// pause the game
void GameController::pauseGame() {
    game.pause();
}

// resume a paused game
void GameController::resumeGame() {
    game.resume();
}
