// gameview.cpp
#include "../../include/view/gameview.h"
#include <android/bitmap.h>

GameView::GameView(GameController& controller, JNIEnv *env, jobject assetManager)
        : gameController(controller), env(env), assetManager(assetManager) {
    loadBitmaps();
}

void GameView::initialize() {
    // Initialize the view
}

void GameView::drawGameScreen() {
    // Draw the game screen
    drawBitmap(paddleBitmap, gameController.getPaddleX(), gameController.getPaddleY());
    drawBitmap(ballBitmap, gameController.getBallX(), gameController.getBallY());
    for (const auto& block : gameController.getBlocks()) {
        drawBitmap(blockBitmaps[block.getType()], block.getX(), block.getY());
    }
}

void GameView::onTouchInput(int touchX, int touchY) {
    // Handle touch input
    gameController.handleTouchInput(touchX, touchY);
}

void GameView::onKeyboardInput(int keyCode) {
    // Handle keyboard input
}

void GameView::loadBitmaps() {
    paddleBitmap = loadBitmap("paddle.png");
    ballBitmap = loadBitmap("ball.png");
    blockBitmaps[0] = loadBitmap("block1.png");
    blockBitmaps[1] = loadBitmap("block2.png");
    blockBitmaps[2] = loadBitmap("block3.png");
}

jobject GameView::loadBitmap(const char *fileName) {
    AAssetManager *mgr = AAssetManager_fromJava(env, assetManager);
    AAsset *asset = AAssetManager_open(mgr, fileName, AASSET_MODE_BUFFER);
    off_t size = AAsset_getLength(asset);
    unsigned char *buffer = new unsigned char[size];
    AAsset_read(asset, buffer, size);
    AAsset_close(asset);

    jclass bitmapFactoryClass = env->FindClass("android/graphics/BitmapFactory");
    jmethodID decodeStreamMethod = env->GetStaticMethodID(bitmapFactoryClass, "decodeByteArray", "([BII)Landroid/graphics/Bitmap;");
    jbyteArray byteArray = env->NewByteArray(size);
    env->SetByteArrayRegion(byteArray, 0, size, reinterpret_cast<jbyte*>(buffer));
    jobject bitmap = env->CallStaticObjectMethod(bitmapFactoryClass, decodeStreamMethod, byteArray, 0, size);

    delete[] buffer;
    return bitmap;
}

void GameView::drawBitmap(jobject bitmap, float x, float y) {
    jclass canvasClass = env->FindClass("android/graphics/Canvas");
    jmethodID drawBitmapMethod = env->GetMethodID(canvasClass, "drawBitmap", "(Landroid/graphics/Bitmap;FFLandroid/graphics/Paint;)V");
    jmethodID getCanvasMethod = env->GetMethodID(SurfaceView, "getHolder", "()Landroid/view/SurfaceHolder;");
    jobject surfaceHolder = env->CallObjectMethod(surfaceView, getCanvasMethod);
    jobject canvas = env->CallObjectMethod(surfaceHolder, getCanvasMethod);

    jclass paintClass = env->FindClass("android/graphics/Paint");
    jmethodID paintConstructor = env->GetMethodID(paintClass, "<init>", "()V");
    jobject paint = env->NewObject(paintClass, paintConstructor);

    env->CallVoidMethod(canvas, drawBitmapMethod, bitmap, x, y, paint);
}
