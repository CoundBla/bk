#include <jni.h>
#include <string>
#include "../../include/controller/gamecontroller.h"

extern "C" {

// Game controller instance
static GameController gameController;

// Function to initialize the game
JNIEXPORT void JNICALL
Java_com_example_nativebreakout_NativeLib_initializeGame(JNIEnv *env, jobject thiz) {
gameController = GameController();
// Implement initialization logic here
}

// Function to handle input from the user
JNIEXPORT void JNICALL
Java_com_example_nativebreakout_NativeLib_handleInput(JNIEnv *env, jobject thiz, jint touchX) {
gameController.handleInput(touchX);
}

// Function to update the game state
JNIEXPORT void JNICALL
Java_com_example_nativebreakout_NativeLib_updateGame(JNIEnv *env, jobject thiz, jfloat deltaTime) {
gameController.updateGame(deltaTime);
}

// Function to handle game over
JNIEXPORT void JNICALL
Java_com_example_nativebreakout_NativeLib_handleGameOver(JNIEnv *env, jobject thiz) {
gameController.handleGameOver();
}

// Function to pause the game
JNIEXPORT void JNICALL
Java_com_example_nativebreakout_NativeLib_pauseGame(JNIEnv *env, jobject thiz) {
gameController.pauseGame();
}

// Function to resume the game
JNIEXPORT void JNICALL
Java_com_example_nativebreakout_NativeLib_resumeGame(JNIEnv *env, jobject thiz) {
gameController.resumeGame();
}

} // extern "C"
