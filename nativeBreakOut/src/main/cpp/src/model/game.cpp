#include "../../include/model/game.h"

// Constructor
Game::Game() : m_Score(0), m_Lives(3), m_GameOver(false), m_Paused(false) {
    // Inicializar otros objetos del juego aqu� si es necesario
}

// M�todos de acceso para obtener datos del juego
int Game::getScore() const {
    return m_Score;
}

int Game::getLives() const {
    return m_Lives;
}

bool Game::isGameOver() const {
    return m_GameOver;
}

bool Game::isPaused() const {
    return m_Paused;
}

// M�todos para pausar y reanudar el juego
void Game::pause() {
    m_Paused = true;
}

void Game::resume() {
    m_Paused = false;
}

// Otros m�todos para obtener objetos del juego
Paddle& Game::getPaddle() {
    return m_Paddle;
}

Ball& Game::getBall() {
    return m_Ball;
}

std::vector<Block>& Game::getBlocks() {
    return m_Blocks;
}
