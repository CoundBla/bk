package com.example.nativebreakout

class NativeLib {

    // Funciones nativas que serán implementadas en C++
    external fun initializeGame()
    external fun handleInput(touchX: Int, touchY: Int)
    external fun updateGame(deltaTime: Float)
    external fun handleGameOver()
    external fun pauseGame()
    external fun resumeGame()

    companion object {
        // Cargar la biblioteca nativa al iniciar la aplicación
        init {
            System.loadLibrary("nativebreakout")
        }
    }
}
