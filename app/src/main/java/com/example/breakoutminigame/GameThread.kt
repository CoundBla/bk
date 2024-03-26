package com.example.breakoutminigame

import android.view.SurfaceHolder
import com.example.nativebreakout.NativeLib
class GameThread(private val holder: SurfaceHolder) : Thread() {
    private val FPS = 60 // Frames per second
    private var running = false
    private val nativeLib = NativeLib()

    override fun run() {
        var startTime: Long
        var deltaTime: Float

        while (running) {
            startTime = System.currentTimeMillis()

            val canvas = holder.lockCanvas()
            if (canvas != null) {
                // Update game state
                deltaTime = (System.currentTimeMillis() - startTime) / 1000f
                nativeLib.updateGame(deltaTime)

                // Draw game screen here (using canvas)
                // You can call native methods to get drawing data
                // (consider implementing draw methods in the native GameView class)

                holder.unlockCanvasAndPost(canvas)
            }

            // Sleep to maintain desired FPS
            val sleepTime = (1000 / FPS - (System.currentTimeMillis() - startTime)).toLong()
            if (sleepTime > 0) {
                try {
                    sleep(sleepTime)
                } catch (e: InterruptedException) {
                    e.printStackTrace()
                }
            }
        }
    }

    fun setRunning(isRunning: Boolean) {
        running = isRunning
    }
}
