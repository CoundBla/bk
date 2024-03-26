#include "../../include/controller/collisioncontroller.h"
#include "../../include/model//paddle.h"
// Constructor
CollisionController::CollisionController(Paddle& paddle, Ball& ball, std::vector<Block>& blocks)
    : paddle(paddle), ball(ball), blocks(blocks) {}

// M�todo para detectar colisiones entre la bola y los bloques
void CollisionController::detectCollisions() {
    // Detectar colisi�n entre la bola y la paleta
    if (checkBallPaddleCollision()) {
        ball.reverseVelocityY();
    }

    // Iterar sobre todos los bloques para detectar colisiones con la bola
    for (auto& block : blocks) {
        if (checkBallBlockCollision(block)) {
            // Realizar acciones apropiadas para la colisi�n (por ejemplo, eliminar el bloque)
            ball.reverseVelocityY(); // Ejemplo: invertir la velocidad en Y de la bola
            block.reduceHealth(); // Ejemplo: reducir la salud del bloque
        }
    }
}

// M�todo privado para detectar colisi�n entre la bola y la paleta
bool CollisionController::checkBallPaddleCollision() {
    // Calcular las coordenadas del borde de la paleta
    float paddleLeft = paddle.getX();
    float paddleRight = paddle.getX() + paddle.getWidth();
    float paddleTop = paddle.getY();
    float paddleBottom = paddle.getY() + paddle.getHeight();

    // Calcular las coordenadas del borde de la bola
    float ballLeft = ball.getX() - ball.getRadius();
    float ballRight = ball.getX() + ball.getRadius();
    float ballTop = ball.getY() - ball.getRadius();
    float ballBottom = ball.getY() + ball.getRadius();

    // Verificar si hay intersecci�n entre los rect�ngulos del paddle y la bola
    return ballRight >= paddleLeft && ballLeft <= paddleRight && ballBottom >= paddleTop && ballTop <= paddleBottom;
}

// M�todo privado para detectar colisi�n entre la bola y un bloque espec�fico
bool CollisionController::checkBallBlockCollision(const Block& block) {
    // Calcular las coordenadas del borde del bloque
    float blockLeft = block.getX();
    float blockRight = block.getX() + block.getWidth();
    float blockTop = block.getY();
    float blockBottom = block.getY() + block.getHeight();

    // Calcular las coordenadas del borde de la bola
    float ballLeft = ball.getX() - ball.getRadius();
    float ballRight = ball.getX() + ball.getRadius();
    float ballTop = ball.getY() - ball.getRadius();
    float ballBottom = ball.getY() + ball.getRadius();

    // Verificar si hay intersecci�n entre los rect�ngulos del bloque y la bola
    return ballRight >= blockLeft && ballLeft <= blockRight && ballBottom >= blockTop && ballTop <= blockBottom;
}
