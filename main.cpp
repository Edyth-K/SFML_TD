#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <iostream>

bool hasMouseOver(sf::RectangleShape rect, sf::Vector2i mouse)
{
    return false;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tower Defense");

    ImGui::SFML::Init(window);
    sf::Clock deltaClock;

    std::vector<sf::RectangleShape> tile(16);

    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            sf::RectangleShape shape(sf::Vector2f(50, 50));
            shape.setFillColor(sf::Color::Green);
            shape.setPosition(i*100, j*100);
            tile.push_back(shape);
        }


    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i position = sf::Mouse::getPosition(window);
                std::cout << "X: " << position.x << " Y: " << position.y << std::endl;
                for (auto& rect : tile)
                {
                    if (rect.getTextureRect().contains(position))
                    {
                        rect.setFillColor(sf::Color::Red);
                    }
                    else {
                        rect.setFillColor(sf::Color::Green);
                    }
                }
            }
        }
        ImGui::SFML::Update(window, deltaClock.restart());
        
        // IMGUI
        ImGui::Begin("Window title");
        ImGui::Text("Window text!");
        ImGui::End();

        // GAME LOGIC
        //  <insert here>
        //sf::Vector2i position = sf::Mouse::getPosition(window);
        //std::cout << "X: " << position.x << " Y: " << position.y << std::endl;

   

        // RENDERING
        window.clear();

        for (const auto& rect : tile)
        {
            window.draw(rect);
        }
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return 0;
}