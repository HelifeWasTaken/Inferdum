#include "Kat/window.h"

namespace kat {

    Window& Window::create(sf::WindowHandle handle, const sf::ContextSettings& settings)
    {
        m_window.create(handle, settings);
        return *this;
    }

    Window& Window::create(sf::VideoMode mode, const std::string& title, sf::Uint32 style, const sf::ContextSettings& settings)
    {
        m_window.create(mode, title, style, settings);
        return *this;
    }

    Window::Window(sf::VideoMode mode, const std::string& title, sf::Uint32 style, const sf::ContextSettings& settings)
    {
        create(mode, title, style, settings);
    }

    Window::Window(sf::WindowHandle handle, const sf::ContextSettings& settings)
    {
        create(handle, settings);
    }

    Window& Window::close()
    {
        m_window.close();
        return *this;
    }

    bool Window::isOpen() const
    {
        return m_window.isOpen();
    }

    bool Window::poll(sf::Event& event)
    {
        return m_window.pollEvent(event);
    }

    Window& Window::setFps(unsigned int limit)
    {
        m_window.setFramerateLimit(limit);
        return *this;
    }

    bool Window::hasFocus() const
    {
        return m_window.hasFocus();
    }

    sf::RenderWindow& Window::getHandle()
    {
        return m_window;
    }

    const sf::RenderWindow& Window::getHandle() const
    {
        return m_window;
    }
}