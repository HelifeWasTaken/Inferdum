#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <imgui.h>

#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <windows.h>
int main() {
    BuiltinWindow window(sf::VideoMode(sf::Vector2u(1280, 720)), "ImGui + SFML = <3");

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::SFML::Init(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, sf::seconds(1.f / 60.f));

        ImGui::Begin("Hello, world!");
        // demo window
        ImGui::ShowDemoWindow();
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }
}