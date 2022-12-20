#include "Kat/components/sprite.h"
#include "Kat/math.h"

namespace kat {

    Sprite& Sprite::create(Texture& texture)
    {
        m_texture = texture;
        m_sprite->setTexture(*texture.raw_handle());
        return *this;
    }

    Sprite& Sprite::create(const shared_texture_t& texture)
    {
        m_texture = Texture(texture);
        m_sprite->setTexture(*texture);
        return *this;
    }

    Sprite& Sprite::create(sf::Texture* texture)
    {
        m_sprite->setTexture(*texture);
        m_texture = Texture(texture);
        return *this;
    }

    Sprite& Sprite::setPosition(const Coordinate& x, const Coordinate& y)
    {
        m_sprite->setPosition(x, y);
        return *this;
    }

    Sprite& Sprite::setPosition(const Position& position)
    {
        return setPosition(position.x, position.y);
    }

    Sprite& Sprite::setRotation(const Angle& angle, const bool& is_radians)
    {
        m_sprite->setRotation(is_radians ? math::asDegrees(angle) : angle);
        return *this;
    }

    Sprite& Sprite::setScale(const ScaleFactor& x, const ScaleFactor& y)
    {
        m_sprite->setScale(x, y);
        return *this;
    }

    Sprite& Sprite::setScale(const Scale& scale)
    {
        return setScale(scale.x, scale.y);
    }

    Sprite& Sprite::setOrigin(const Coordinate& x, const Coordinate& y)
    {
        m_sprite->setOrigin(x, y);
        return *this;
    }

    Sprite& Sprite::setOrigin(const Position& origin)
    {
        return setOrigin(origin.x, origin.y);
    }

    const Position& Sprite::getPosition() const
    {
        return m_sprite->getPosition();
    }

    Angle Sprite::getRotation(bool as_radians) const
    {
        return as_radians ?
            math::asRadians(m_sprite->getRotation()) :
            m_sprite->getRotation();
    }

    const Scale& Sprite::getScale() const
    {
        return m_sprite->getScale();
    }

    const Position& Sprite::getOrigin() const
    {
        return m_sprite->getOrigin();
    }

    Sprite& Sprite::move(const Coordinate& x, const Coordinate& y)
    {
        m_sprite->move(x, y);
        return *this;
    }

    Sprite& Sprite::move(const Position& offset)
    {
        return move(offset.x, offset.y);
    }

    Sprite& Sprite::rotate(const Angle& angle, bool is_radians)
    {
        m_sprite->rotate(is_radians ? math::asDegrees(angle) : angle);
        return *this;
    }

    Sprite& Sprite::scale(const ScaleFactor& x, const ScaleFactor& y)
    {
        m_sprite->scale(x, y);
        return *this;
    }

    Sprite& Sprite::scale(const Scale& pscale)
    {
        return scale(pscale.x, pscale.y);
    }

    Sprite& Sprite::scale(const ScaleFactor& factor)
    {
        return scale(factor, factor);
    }

    const Transform& Sprite::getTransform() const
    {
        return m_sprite->getTransform();
    }

    const Transform& Sprite::getInverseTransform() const
    {
        return m_sprite->getInverseTransform();
    }

    void Sprite::draw(Window& window) const
    {
        window.draw(*m_sprite);
    }

    Sprite& Sprite::setTextureRect(const Frame& frame)
    {
        m_sprite->setTextureRect(frame);
        return *this;
    }

    const Frame& Sprite::getTextureRect() const
    {
        return m_sprite->getTextureRect();
    }

    Sprite& Sprite::setColor(const Color& color)
    {
        m_sprite->setColor(color);
        return *this;
    }

    const Texture& Sprite::getTexture() const
    {
        return m_texture;
    }

    Texture& Sprite::getTexture()
    {
        return m_texture;
    }

    const Color& Sprite::getColor() const
    {
        return m_sprite->getColor();
    }

    const GlobalBounds Sprite::getGlobalBounds() const
    {
        return m_sprite->getGlobalBounds();
    }

    const LocalBounds Sprite::getLocalBounds() const
    {
        return m_sprite->getLocalBounds();
    }

    const sf::Sprite *Sprite::raw_handle() const
    {
        return m_sprite.get();
    }

    shared_drawable_t Sprite::as_drawable() const
    {
        return m_sprite;
    }
}