#pragma once

#include "../meta.h"
#include "../window.h"
#include "./vector.h"

#include <SFML/Graphics/Texture.hpp>

#include <memory>
#include <string>

namespace inferdum {

    using shared_texture_t = std::shared_ptr<sf::Texture>;

    class Texture {
    public:
        /**
         * @brief Loads a texture from a texture pointer.
         * @param texture The texture pointer.
         * @return Texture& Reference to self.
         */
        Texture& load(sf::Texture* texture);

        /**
         * @brief Loads a texture from a shared texture pointer.
         * @param texture The shared texture pointer.
         * @return Texture& Reference to self.
         */
        Texture& load(shared_texture_t& texture);

        /**
         * @brief Loads a texture from a file.
         * @param filename The filename of the texture.
         * @param area The area of the texture.
         * @return Texture& Reference to self.
         */
        Texture& load(const std::string& filename,
                      const sf::IntRect& area = sf::IntRect());

        /**
         * @brief Loads a texture from memory.
         * 
         * @param data The data of the texture.
         * @param size The size of the data.
         * @param area The area of the texture.
         * @return Texture& Reference to self.
         */
        Texture& load(const void* data, std::size_t size,
                      const sf::IntRect& area = sf::IntRect());

        /**
         * @brief Loads a texture from a file.
         * 
         * @param width The width of the texture.
         * @param height The height of the texture.
         * @return Texture& Reference to self.
         */
        Texture& create(u32 width, u32 height);

        /**
         * @brief Gets the size of the texture.
         * 
         * @return Vector2u The size of the texture.
         */
        Vector2u size() const;

        /**
         * @brief Updates the texture.
         * 
         * @param pixels The pixels of the texture.
         * @return Texture& Reference to self.
         */
        Texture& update(const u8* pixels);

        /**
         * @brief Updates the texture.
         * 
         * @param pixels The pixels of the texture.
         * @param width The width of the texture.
         * @param height The height of the texture.
         * @param x The x position of the texture.
         * @param y The y position of the texture.
         * @return Texture& Reference to self.
         */
        Texture& update(const u8* pixels, u32 width, u32 height, u32 x, u32 y);

        /**
         * @brief Updates the texture from a sfml raw texture pointer.
         * 
         * @param sfml_texture 
         * @return Texture& 
         */
        Texture& update(const sf::Texture *sfml_texture);

        /**
         * @brief Updates the texture from a sfml raw texture pointer.
         * 
         * @param sfml_texture The sfml raw texture pointer.
         * @param x The x position of the texture.
         * @param y The y position of the texture.
         * @return Texture& Reference to self.
         */
        Texture& update(const sf::Texture *sfml_texture, u32 x, u32 y);

        /**
         * @brief Updates the texture from another texture.
         *
         * @param texture The texture to update from.
         * @return Texture& Reference to self.
         */
        Texture& update(const Texture& texture);

        /**
         * @brief Updates the texture from another texture.
         *
         * @param texture The texture to update from.
         * @param x The x position of the texture.
         * @param y The y position of the texture.
         * @return Texture& Reference to self.
         */
        Texture& update(const Texture& texture, u32 x, u32 y);

        /**
         * @brief Updates the texture from a window.
         *
         * @param sfml_window The sfml raw window pointer.
         * @return Texture& Reference to self.
         */
        Texture& update(const sf::Window& sfml_window);

        /**
         * @brief Updates the texture from a window.
         *
         * @param sfml_window The sfml raw window pointer.
         * @param x The x position of the texture.
         * @param y The y position of the texture.
         * @return Texture& Reference to self.
         */
        Texture& update(const sf::Window& sfml_window, u32 x, u32 y);

        /**
         * @brief Updates the texture from a window.
         * 
         * @param window The window to update from.
         * @return Texture& Reference to self.
         */
        Texture& update(const Window& window);

        /**
         * @brief Updates the texture from a window.
         * 
         * @param window The window to update from.
         * @param x The x position of the texture.
         * @param y The y position of the texture.
         * @return Texture& Reference to self.
         */
        Texture& update(const Window& window, u32 x, u32 y);

        /**
         * @brief Set the Smooth object
         * 
         * @param smooth 
         * @return Texture& 
         */
        Texture& setSmooth(bool smooth);

        /**
         * @brief Is the texture smooth?
         * 
         * @return true The texture is smooth.
         * @return false The texture is not smooth.
         */
        bool isSmooth() const;

        /**
         * @brief Set the Repeated object
         * 
         * @param repeated 
         * @return Texture& 
         */
        bool repeated() const;

        /**
         * @brief Is the texture repeated?
         * 
         * @return true The texture is repeated.
         * @return false The texture is not repeated.
         */
        bool repeated(bool rep);

        /**
         * @brief Get the native handle of the texture.
         * 
         * @return sf::Texture* The native handle of the texture.
         */
        sf::Texture* raw_handle();

        /**
         * @brief Construct a new Texture object
         */
        Texture();

        /**
         * @brief Construct a new Texture object
         * @param texture 
         */
        Texture(sf::Texture* texture);

        /**
         * @brief Construct a new Texture object
         * @param texture 
         * @return Texture& 
         */
        Texture& operator=(sf::Texture* texture);

        /**
         * @brief Construct a new Texture object
         * @param texture 
         */
        Texture(const shared_texture_t& texture);

        /**
         * @brief Construct a new Texture object
         * @param texture 
         * @return Texture& 
         */
        Texture& operator=(const shared_texture_t& texture);

        /**
         * @brief Construct a new Texture object
         * 
         * @param texture 
         */
        Texture(shared_texture_t&& texture);

        /**
         * @brief Construct a new Texture object
         * 
         * @param texture 
         * @return Texture& 
         */
        Texture& operator=(shared_texture_t&& texture);

        /**
         * @brief Construct a new Texture object
         * 
         * @param texture 
         */
        Texture(const Texture&) = default;

        /**
         * @brief Construct a new Texture object
         * 
         * @param texture 
         * @return Texture& 
         */
        Texture& operator=(const Texture&) = default;

        /**
         * @brief Construct a new Texture object
         * 
         * @param texture 
         */
        Texture(Texture&&) = default;

        /**
         * @brief Construct a new Texture object
         * 
         * @param texture 
         * @return Texture& 
         */
        Texture& operator=(Texture&&) = default;

    private:
        shared_texture_t m_texture;
    };
}