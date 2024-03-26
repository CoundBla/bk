// gameview.h
#pragma once
#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "../controller/GameController.h"
#include <jni.h>

class GameView {
public:
    GameView(GameController& controller, JNIEnv *env, jobject assetManager);

    void initialize();
    void drawGameScreen();
    void onTouchInput(int touchX, int touchY);
    void onKeyboardInput(int keyCode);

private:
    GameController& gameController;
    JNIEnv *env;
    jobject assetManager;
    jobject paddleBitmap;
    jobject ballBitmap;
    jobject blockBitmaps[3];

    void loadBitmaps();
    void drawBitmap(jobject bitmap, float x, float y);
    jobject loadBitmap(const char *fileName);
};

#endif // GAMEVIEW_H
