#pragma once

#include "./vector.h"

#include <glm/ext/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace inferdum {

    /**
     * @brief Transform an inferdum::Vector2 to a glm::vec2
     *
     * @param vec The inferdum::Vector2 to transform
     * @return glm::vec2 The transformed glm::vec2
     */
    glm::vec2 as_glm_vec2(const Vector2f& vec);

    /**
     * @brief Transform an inferdum::Vector3 to a glm::vec3
     *
     * @param vec The inferdum::Vector3 to transform
     * @return glm::vec3 The transformed glm::vec3
     */
    glm::vec3 as_glm_vec3(const Vector3f& vec);

    /**
     * @brief Transform an inferdum::Vector4 to a glm::vec4
     *
     * @param vec The inferdum::Vector4 to transform
     * @return glm::vec4 The transformed glm::vec4
     */
    glm::vec4 as_glm_vec4(const Vector4f& vec);

    /**
     * @brief Representation of a 2D transformation
     *
     */
    struct Transform2D {
    private:
        Vector2f m_origin   = Vector2f(0, 0);
        Vector2f m_position = Vector2f(0, 0);
        Vector2f m_scale    = Vector2f(1, 1);
        float    m_rotation = 0;
        float    m_depth    = 0;

        mutable bool      m_matrix_cache_dirty     = true;
        mutable bool      m_matrix_cache_inv_dirty = true;
        mutable glm::mat4 m_matrix_cache;
        mutable glm::mat4 m_matrix_cache_inv;

        /**
         * @brief Tells that the matrix needs to be recalculated
         *
         * @return Transform2D& self reference
         */
        Transform2D& _set_matrix_cache_dirty();

        /**
         * @brief Gets the matrix from the cache and recalculates it if needed
         *
         * @return const glm::mat4& The matrix
         */
        const glm::mat4& _get_matrix_cache() const;

        /**
         * @brief Gets the matrix from the cache and recalculates it if needed
         *        then returns the inverse of the matrix.
         *        The inverse is cached as well.
         *
         * @return const glm::mat4& The inverse matrix
         */
        const glm::mat4& _get_matrix_cache_inv() const;

    public:
        const Vector2f& origin   = this->m_origin;
        const Vector2f& position = this->m_position;
        const Vector2f& scale    = this->m_scale;
        const float&    rotation = this->m_rotation;
        const float&    depth    = this->m_depth;

        /**
         * @brief Construct a new Transform 2D object
         */
        Transform2D() = default;

        /**
         * @brief Destroy the Transform 2D object
         */
        ~Transform2D() = default;

        /**
         * @brief Gets the current matrix transformation
         *
         * @return const glm::mat4& The matrix
         */
        const glm::mat4& matrix() const;

        /**
         * @brief Gets the current inverse matrix transformation
         *
         * @return const glm::mat4& The inverse matrix
         */
        const glm::mat4& matrixInv() const;

        /**
         * @brief Set the scale of the transformation
         *
         * @param scale The new scale
         * @return Transform2D& self reference
         */
        Transform2D& setScale(const Vector2f& scale);

        /**
         * @brief Set the scale of the transformation
         *
         * @param x The new x scale
         * @param y The new y scale
         * @return Transform2D& self reference
         */
        Transform2D& setScale(const float& x, const float& y);

        /**
         * @brief Set the scale of the transformation
         *
         * @param ratio The new scale ratio where x = y = ratio
         * @return Transform2D& self reference
         */
        Transform2D& setScale(const float& ratio);

        /**
         * @brief Set the depth of the transformation (z axis)
         * The depth will not be used in the matrix and must be used
         * separately.
         * As this is a 2D transformation, the depth is an hint for the
         * renderer.
         *
         * @param rotation The new depth
         * @return Transform2D& self reference
         */
        Transform2D& setDepth(const float& ndepth);

        /**
         * @brief Set the position of the transformation in a 2.5D space
         * The x and y coordinates will be used in the matrix and the z
         * coordinate will be used as the depth. (See setDepth)
         *
         * @param position The new position
         * @return Transform2D& self reference
         */
        Transform2D& setPosition(const Vector3<float>& position);

        /**
         * @brief Set the position of the transformation in a 2.5D space
         * The x and y coordinates will be used in the matrix and the z
         * coordinate will be used as the depth. (See setDepth)
         *
         * @param x The new x position
         * @param y The new y position
         * @param z The new depth
         * @return Transform2D& self reference
         */
        Transform2D& setPosition(const float& x, const float& y,
                                 const float& z);

        /**
         * @brief Set the position of the transformation in a 2D space.
         *
         * @param position The new position
         * @return Transform2D& self reference
         */
        Transform2D& setPosition(const Vector2f& position);

        /**
         * @brief Set the position of the transformation in a 2D space.
         *
         * @param x The new x position
         * @param y The new y position
         * @return Transform2D& self reference
         */
        Transform2D& setPosition(const float& x, const float& y);

        /**
         * @brief Set the origin of the transformation
         *
         * @param origin The new origin
         * @return Transform2D& self reference
         */
        Transform2D& setOrigin(const Vector2f& origin);

        /**
         * @brief Set the origin of the transformation
         *
         * @param x The new x origin
         * @param y The new y origin
         * @return Transform2D& self reference
         */
        Transform2D& setOrigin(const float& x, const float& y);

        /**
         * @brief Set the rotation of the transformation
         *
         * @param rotation The new rotation
         * @return Transform2D& self reference
         */
        Transform2D& setRotation(const float& rotation,
                                 bool         is_radians = false);

        /**
         * @brief Linear interpolation between two transformations
         */
        static Transform2D s_lerp(const Transform2D& a, const Transform2D& b,
                                  const float& t);

        /**
         * @brief Linear interpolation between self and another transformation
         */
        Transform2D& lerp(const Transform2D& other, const float& t);

        /**
         * @brief Copy constructor
         */
        Transform2D(const Transform2D& other);

        /**
         * @brief Assignmenent copy constructor
         */
        Transform2D& operator=(const Transform2D& other);
    };

}