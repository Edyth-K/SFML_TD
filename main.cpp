#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h" // Include the Enemy class

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tower Defense");

    ImGui::SFML::Init(window);
    sf::Clock deltaClock;

    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("images/ghost.png");

    // Create an instance of the Enemy class
    sf::Vector2f startPosition(100.0f, 100.0f);
    float speed = 0.5f; // Adjust the speed as needed
    int health = 100;

    Enemy enemy(startPosition, speed, health);

    // Associate the texture with the sprite directly in your code
    enemy.setTexture(enemyTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();

        }
        ImGui::SFML::Update(window, deltaClock.restart());
        
        // IMGUI
        ImGui::Begin("Window title");
        ImGui::Text("Window text!");
        ImGui::End();

        // GAME LOGIC

        // Move the enemy towards a target position
        sf::Vector2f targetPosition(400.0f, 300.0f);
        enemy.move(targetPosition);
   

        // RENDERING
        window.clear();


        enemy.render(window);
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return 0;
}