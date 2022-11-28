#include "Inferdum/components/texture.h"

namespace inferdum {

    Texture& Texture::load(sf::Texture* texture)
    {
        m_texture = std::shared_ptr<sf::Texture>(texture);
        return *this;
    }

    Texture& Texture::load(shared_texture_t& texture)
    {
        m_texture = texture;
        return *this;
    }

    Texture& Texture::load(const std::string& filename, const sf::IntRect& area)
    {
        m_texture = std::make_shared<sf::Texture>();
        if (m_texture->loadFromFile(filename, area) == false) {
            m_texture = nullptr;
        }
        return *this;
    }

    Texture& Texture::load(const void* data, std::size_t size, const sf::IntRect& area)
    {
        m_texture = std::make_shared<sf::Texture>();
        if (m_texture->loadFromMemory(data, size, area) == false) {
            m_texture = nullptr;
        }
        return *this;
    }

    Texture& Texture::create(u32 width, u32 height)
    {
        m_texture = std::make_shared<sf::Texture>();
        if (m_texture->create(width, height) == false) {
            m_texture = nullptr;
        }
        return *this;
    }

    Vector2u Texture::size() const
    {
        return Vector2u(m_texture->getSize().x, m_texture->getSize().y);
    }

    Texture& Texture::update(const u8* pixels)
    {
        m_texture->update(pixels);
        return *this;
    }

    Texture& Texture::update(const u8* pixels, u32 width, u32 height, u32 x, u32 y)
    {
        m_texture->update(pixels, width, height, x, y);
        return *this;
    }

    Texture& Texture::update(const sf::Texture *sfml_texture)
    {
        m_texture->update(*sfml_texture);
        return *this;
    }

    Texture& Texture::update(const sf::Texture *sfml_texture, u32 x, u32 y)
    {
        m_texture->update(*sfml_texture, x, y);
        return *this;
    }

    Texture& Texture::update(const Texture& texture)
    {
        m_texture->update(*texture.m_texture);
        return *this;
    }

    Texture& Texture::update(const Texture& texture, u32 x, u32 y)
    {
        m_texture->update(*texture.m_texture, x, y);
        return *this;
    }

    Texture& Texture::update(const sf::Window& sfml_window)
    {
        m_texture->update(sfml_window);
        return *this;
    }

    Texture& Texture::update(const sf::Window& sfml_window, u32 x, u32 y)
    {
        m_texture->update(sfml_window, x, y);
        return *this;
    }

    Texture& Texture::update(const Window& window)
    {
        return update(window.getHandle());
    }

    Texture& Texture::update(const Window& window, u32 x, u32 y)
    {
        return update(window.getHandle(), x, y);
    }

    Texture& Texture::setSmooth(bool smooth)
    {
        m_texture->setSmooth(smooth);
        return *this;
    }

    bool Texture::isSmooth() const { return m_texture->isSmooth(); }

    bool Texture::repeated() const { return m_texture->isRepeated(); }

    bool Texture::repeated(bool rep)
    {
        m_texture->setRepeated(rep);
        return repeated();
    }

    sf::Texture* Texture::raw_handle() { return m_texture.get(); }

    Texture::Texture()
        : m_texture(std::make_shared<sf::Texture>())
    {
    }

    Texture::Texture(sf::Texture* texture)
        : m_texture(texture)
    {
    }

    Texture& Texture::operator=(sf::Texture* texture)
    {
        m_texture = shared_texture_t(texture);
        return *this;
    }

    Texture::Texture(const shared_texture_t& texture)
        : m_texture(texture)
    {
    }

    Texture& Texture::operator=(const shared_texture_t& texture)
    {
        m_texture = texture;
        return *this;
    }

    Texture::Texture(shared_texture_t&& texture)
        : m_texture(std::move(texture))
    {
    }

    Texture& Texture::operator=(shared_texture_t&& texture)
    {
        m_texture = std::move(texture);
        return *this;
    }

}