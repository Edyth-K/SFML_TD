
#include "Enemy.h" // Include the class header
#include <cmath>   // For advanced math operations, if needed

// Constructor implementation
Enemy::Enemy(sf::Vector2f startPosition, float speed, int health)
    : position(startPosition), speed(speed), health(health) {
    // Initialize sprite position
    sprite.setPosition(position);
}

// Move function implementation
void Enemy::move(const sf::Vector2f& targetPosition) {
    // Simple movement logic: move towards the target
    sf::Vector2f direction = targetPosition - position;

    // Normalize direction and scale by speed
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0.0f) {
        direction /= length; // Normalize
    }

    // Update position
    position += direction * speed;
    sprite.setPosition(position);
}

// Render function implementation
void Enemy::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Enemy::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
}
