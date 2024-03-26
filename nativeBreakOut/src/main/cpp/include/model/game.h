#pragma once
#ifndef GAME_H
#define GAME_H

#include "paddle.h"
#include "ball.h"
#include "block.h"

class Game {
public:
    // Constructor
    Game();

    // Métodos de acceso para obtener datos del juego
    int getScore() const;
    int getLives() const;
    bool isGameOver() const;
    bool isPaused() const;

    // Métodos para pausar y reanudar el juego
    void pause();
    void resume();

    // Otros objetos del juego
    Paddle& getPaddle();
    Ball& getBall();
    std::vector<Block>& getBlocks();

private:
    // Datos del estado del juego
    int m_Score; // Puntuación del jugador
    int m_Lives; // Vidas restantes
    bool m_GameOver; // Indica si el juego ha terminado
    bool m_Paused; // Indica si el juego está pausado

    // Otros objetos del juego
    Paddle m_Paddle; // La paleta del jugador
    Ball m_Ball; // La bola del juego
    std::vector<Block> m_Blocks; // Vector de bloques en el juego
};

#endif // GAME_H
