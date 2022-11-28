#include "Inferdum/components/transform.h"

namespace inferdum {

    glm::vec2 as_glm_vec2(const Vector2f& vec)
    {
        return glm::vec3(vec.x, vec.y, 0.0f);
    }

    glm::vec3 as_glm_vec3(const Vector3<float>& vec)
    {
        return glm::vec3(vec.x, vec.y, vec.z);
    }

    glm::vec4 as_glm_vec4(const Vector4<float>& vec)
    {
        return glm::vec4(vec.x, vec.y, vec.z, vec.w);
    }

    Transform2D& Transform2D::_set_matrix_cache_dirty()
    {
        m_matrix_cache_dirty     = true;
        m_matrix_cache_inv_dirty = true;
        return *this;
    }

    const glm::mat4& Transform2D::_get_matrix_cache() const
    {
        if (m_matrix_cache_dirty) {
            static constexpr glm::vec3 v3rotation = glm::vec3(0.0f, 0.0f, 1.0f);
            static constexpr glm::mat4 identity   = glm::mat4(1.0f);

            const glm::vec3 v3origin = glm::vec3(m_origin.x, m_origin.y, 0.0f);
            const glm::vec3 v3position
                = glm::vec3(m_position.x, m_position.y, 0.0f);
            const glm::vec3 v3scale = glm::vec3(m_scale.x, m_scale.y, 1.0f);

            m_matrix_cache = glm::translate(identity, v3origin)
                * glm::translate(identity, v3position)
                * glm::rotate(identity, m_rotation, v3rotation)
                * glm::scale(identity, v3scale)
                * glm::translate(identity, -v3origin);
            m_matrix_cache_dirty = false;
        }
        return m_matrix_cache;
    }

    const glm::mat4& Transform2D::_get_matrix_cache_inv() const
    {
        if (m_matrix_cache_inv_dirty) {
            m_matrix_cache_inv       = glm::inverse(_get_matrix_cache());
            m_matrix_cache_inv_dirty = false;
        }
        return m_matrix_cache_inv;
    }

    const glm::mat4& Transform2D::matrix() const { return _get_matrix_cache(); }

    const glm::mat4& Transform2D::matrixInv() const
    {
        return _get_matrix_cache_inv();
    }

    Transform2D& Transform2D::setScale(const Vector2f& scale)
    {
        m_scale = scale;
        return _set_matrix_cache_dirty();
    }

    Transform2D& Transform2D::setScale(const float& x, const float& y)
    {
        return setScale(Vector2f(x, y));
    }

    Transform2D& Transform2D::setScale(const float& ratio)
    {
        return setScale(ratio, ratio);
    }

    Transform2D& Transform2D::setDepth(const float& ndepth)
    {
        m_depth = ndepth;
        return *this;
    }

    Transform2D& Transform2D::setPosition(const Vector3<float>& position)
    {
        return setDepth(position.z)
            .setPosition(Vector2f(position.x, position.y));
    }

    Transform2D& Transform2D::setPosition(const float& x, const float& y,
                                          const float& z)
    {
        return setPosition(Vector3<float>(x, y, z));
    }

    Transform2D& Transform2D::setPosition(const Vector2f& position)
    {
        m_position = position;
        return _set_matrix_cache_dirty();
    }

    Transform2D& Transform2D::setPosition(const float& x, const float& y)
    {
        return setPosition(Vector2f(x, y));
    }

    Transform2D& Transform2D::setOrigin(const Vector2f& origin)
    {
        m_origin = origin;
        return _set_matrix_cache_dirty();
    }

    Transform2D& Transform2D::setOrigin(const float& x, const float& y)
    {
        return setOrigin(Vector2f(x, y));
    }

    Transform2D& Transform2D::setRotation(const float& rotation,
                                          bool         is_radians)
    {
        m_rotation = is_radians ? rotation : glm::radians(rotation);
        return _set_matrix_cache_dirty();
    }

    Transform2D Transform2D::s_lerp(const Transform2D& a, const Transform2D& b,
                                    const float& t)
    {
        return Transform2D()
            .setPosition(Vector2f::s_lerp(a.m_position, b.m_position, t))
            .setOrigin(Vector2f::s_lerp(a.m_origin, b.m_origin, t))
            .setScale(Vector2f::s_lerp(a.m_scale, b.m_scale, t))
            .setRotation(glm::mix(a.m_rotation, b.m_rotation, t))
            .setDepth(glm::mix(a.m_depth, b.m_depth, t));
    }

    Transform2D& Transform2D::lerp(const Transform2D& other, const float& t)
    {
        return *this = Transform2D::s_lerp(*this, other, t);
    }

    Transform2D::Transform2D(const Transform2D& other)
        : m_position(other.m_position)
        , m_origin(other.m_origin)
        , m_scale(other.m_scale)
        , m_rotation(other.m_rotation)
        , m_depth(other.m_depth)
    {
    }

    Transform2D& Transform2D::operator=(const Transform2D& other)
    {
        m_position = other.m_position;
        m_origin   = other.m_origin;
        m_scale    = other.m_scale;
        m_rotation = other.m_rotation;
        m_depth    = other.m_depth;

        if (other.m_matrix_cache_dirty) {
            m_matrix_cache_dirty     = true;
            m_matrix_cache_inv_dirty = true;
        } else {
            m_matrix_cache       = other.m_matrix_cache;
            m_matrix_cache_dirty = false;
            if (other.m_matrix_cache_inv_dirty) {
                m_matrix_cache_inv_dirty = true;
            } else {
                m_matrix_cache_inv       = other.m_matrix_cache_inv;
                m_matrix_cache_inv_dirty = false;
            }
        }
        return *this;
    }
}