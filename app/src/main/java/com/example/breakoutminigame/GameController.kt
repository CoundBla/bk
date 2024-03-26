package com.example.breakoutminigame

class GameController {

    external fun initializeGame() // Función JNI para inicializar el juego
    external fun handleInput(touchX: Int) // Función JNI para manejar la entrada del jugador
    external fun updateGame() // Función JNI para actualizar el estado del juego
    external fun handleGameOver() // Función JNI para manejar el fin del juego
    external fun pauseGame() // Función JNI para pausar el juego
    external fun resumeGame() // Función JNI para reanudar el juego

    companion object {
        // Used to load the 'nativebreakout' library on application startup.
        init {
            System.loadLibrary("nativebreakout")
        }
    }
}
