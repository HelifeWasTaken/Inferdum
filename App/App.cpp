#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <imgui.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "ImGui + SFML = <3");
    sf::Clock        deltaClock;

    ImGui::SFML::Init(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Text("This is some useful text.");
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}