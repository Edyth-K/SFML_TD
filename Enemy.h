#pragma once

#include <SFML/Graphics.hpp> // Needed for sf::Vector2f, sf::Sprite, sf::RenderWindow

class Enemy {
public:
    // Constructor
    Enemy(sf::Vector2f startPosition, float speed, int health);

    // Public member functions
    void move(const sf::Vector2f& targetPosition);
    void render(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);

private:
    // Member variables
    sf::Vector2f position;
    sf::Sprite sprite;
    float speed;
    int health;
};