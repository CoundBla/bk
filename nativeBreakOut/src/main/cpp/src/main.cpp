#include "../include/model/game.h"

int main() {
    // Dimensiones de la pantalla del juego
    int screenWidth = 800;
    int screenHeight = 600;

    // Crear una instancia del juego
    Game game(screenWidth, screenHeight);

    // Ejecutar el juego
    game.run();

    return 0;
}
