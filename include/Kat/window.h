#pragma once

#include <string>

#include "meta.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace kat {

    template<typename DrawableObject, typename _Window>
    concept SfmlDrawable = requires(const DrawableObject& drawable, _Window& window) {
        window.draw(drawable);
    };

    template<typename DrawableObject, typename _Window>
    concept KatDrawable = requires(const DrawableObject& drawable, _Window& window) {
        drawable.draw(window);
    };

    class Window {
    public:
        /**
         * @brief Creates a window from a handle.
         * 
         * @param handle The handle of the window.
         * @param settings The settings of the window.
         * @return Window& Reference to self.
         */
        Window& create(sf::WindowHandle handle, const sf::ContextSettings& settings = sf::ContextSettings());

        /**
         * @brief Creates a window from a video mode.
         * 
         * @param mode The video mode of the window.
         * @param title The title of the window.
         * @param style The style of the window.
         * @param settings The settings of the window.
         * @return Window& Reference to self.
         */
        Window& create(sf::VideoMode mode, const std::string& title = "Kat", sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());

        /**
         * @brief Creates a window from a video mode.
         * 
         * @param mode The video mode of the window.
         * @param title The title of the window.
         * @param style The style of the window.
         * @param settings The settings of the window.
         */
        Window(sf::VideoMode mode, const std::string& title = "Kat", sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());

        /**
         * @brief Creates a window from a handle.
         * 
         * @param handle The handle of the window.
         * @param settings The settings of the window.
         */
        Window(sf::WindowHandle handle, const sf::ContextSettings& settings = sf::ContextSettings());

        /**
         * @brief Closes the window.
         * 
         * @return Window& Reference to self.
         */
        Window& close();

        /**
         * @brief Checks if the window is open.
         * 
         * @return true If the window is open.
         * @return false If the window is closed.
         */
        bool isOpen() const;

        /**
         * @brief Polls an event from the window.
         * 
         * @param event The event to poll.
         * @return true If an event was polled.
         * @return false If no event was polled.
         */
        bool poll(sf::Event& event);

        /**
         * @brief Sets the framerate limit of the window.
         * 
         * @param limit The framerate limit.
         * @return Window& Reference to self.
         */
        Window& setFps(unsigned int limit);

        /**
         * @brief Checks if the window has focus.
         * 
         * @return true If the window has focus.
         * @return false If the window does not have focus.
         */
        bool hasFocus() const;

        /**
         * @brief Gets the handle of the window.
         * 
         * @return sf::RenderWindow& The handle of the window.
         */
        sf::RenderWindow& getHandle();

        /**
         * @brief Gets the handle of the window. (const)
         * 
         * @return sf::RenderWindow& The handle of the window.
         */
        const sf::RenderWindow& getHandle() const;

        /**
         * @brief Draws a drawable to the window.
         * @param drawable The drawable to draw.
         * @return Window& Reference to self.
         */
        template<typename Drawable>
        requires KatDrawable<Drawable, Window>
        Window& draw(const Drawable& drawable) {
            drawable.draw(*this);
            return *this;
        }

        /**
         * @brief Draws a drawable to the window.
         * @param drawable The drawable to draw.
         * @return Window& Reference to self.
         */
        template<typename Drawable>
        requires SfmlDrawable<Drawable, sf::RenderWindow>
        Window& draw(const Drawable& drawable) {
            m_window.draw(drawable);
            return *this;
        }

    private:
        sf::RenderWindow m_window;
    };

}