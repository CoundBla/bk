package com.example.breakoutminigame
import com.example.nativebreakout.NativeLib

import android.content.Context
import android.util.AttributeSet
import android.view.MotionEvent
import android.view.SurfaceHolder
import android.view.SurfaceView

class GameView(context: Context, attrs: AttributeSet) : SurfaceView(context, attrs), SurfaceHolder.Callback {
    private val surfaceHolder: SurfaceHolder = holder
    private val nativeLib: NativeLib = NativeLib()
    private var gameThread: GameThread? = null

    init {
        surfaceHolder.addCallback(this)
    }

    override fun surfaceCreated(holder: SurfaceHolder) {
        nativeLib.initializeGame()
        gameThread = GameThread(holder)
        gameThread?.start()
    }

    override fun surfaceChanged(holder: SurfaceHolder, format: Int, width: Int, height: Int) {
        // No action needed
    }

    override fun surfaceDestroyed(holder: SurfaceHolder) {
        gameThread?.interrupt()
    }

    override fun onTouchEvent(event: MotionEvent): Boolean {
        when (event.action) {
            MotionEvent.ACTION_DOWN, MotionEvent.ACTION_MOVE, MotionEvent.ACTION_UP -> {
                nativeLib.handleInput(event.x.toInt(), event.y.toInt())
            }
        }
        return true
    }

    private inner class GameThread(private val holder: SurfaceHolder) : Thread() {
        private val FPS = 60

        override fun run() {
            var startTime: Long = System.currentTimeMillis()
            var deltaTime: Float

            while (!Thread.interrupted()) {
                val canvas = holder.lockCanvas()
                if (canvas != null) {
                    deltaTime = (System.currentTimeMillis() - startTime) / 1000f
                    startTime = System.currentTimeMillis()
                    nativeLib.updateGame(deltaTime)

                    // Draw game elements here
                    // You can call native methods to get drawing data
                    // (consider implementing draw methods in the native GameView class)

                    holder.unlockCanvasAndPost(canvas)
                }

                val sleepTime = (1000 / FPS - (System.currentTimeMillis() - startTime)).toLong()
                if (sleepTime > 0) {
                    Thread.sleep(sleepTime)
                }
            }
        }
    }
}