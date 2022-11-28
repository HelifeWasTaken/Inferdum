#pragma once

#include "../math.h"
#include "../meta.h"

namespace inferdum {

    template <typename T> struct Vector2;

    template <typename T> struct Vector3;

    template <typename T> struct Vector4;

    /**
     * @brief The size type of the Vector
     */
    using vector_size_type_t = size_t;

    /**
     * @brief A Vector of Size N and of Type T (With T being a Number)
     *
     * @tparam T The type of the Vector
     * @tparam N The number of vertices in the Vector
     */
    template <class T, vector_size_type_t N> class Vector {
    public:
        static_assert(N > 1);

    protected:
        T m_vertices[N] = { 0 };

    public:
        /**
         * @brief Get the element in a vector
         *
         * @param index The index of the vertice
         * @return T& The vertice
         */
        T& operator[](const vector_size_type_t& index)
        {
            return m_vertices[index];
        }

        /**
         * @brief Get the element in a vector (const)
         *
         * @param const index The index of the vertice
         * @return const T& The vertice
         */
        const T& operator[](const vector_size_type_t& index) const
        {
            return m_vertices[index];
        }

        /**
         * @brief Get the number of vertices in the Vector (const)
         *
         * @return vec_size_type_t The number of vertices
         */
        vector_size_type_t size() const { return N; }

        /**
         * @brief Get the element in a vector
         * @param const index The index of the vertice
         * @return T& The vertice
         */
        T& at(const vector_size_type_t& index) { return m_vertices[index]; }

        /**
         * @brief Get the element in a vector (const)
         *
         * @param const index The index of the vertice
         * @return const T& The vertice
         */
        const T& at(const vector_size_type_t& index) const
        {
            return m_vertices[index];
        }

        /**
         * @brief Complete canonical form for Vector
         */
        INFERDUM_FULLY_DEFAULT_CANNONICAL_TEMPLATE(Vector, T, N);

        /**
         * @brief Get the current Vector<T, N> as Vector<T2, N2>
         */
        template <class T2, vector_size_type_t N2> Vector<T2, N2> as() const
        {
            Vector<T2, N2>     result;
            vector_size_type_t vertice = 0;

            for (; vertice < N2 && vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice];
            return result;
        }

        /**
         * @brief Get the Vec1 repr
         */
        Vector2<T> asVec2() const;

        /**
         * @brief Get the Vec1 repr
         */
        Vector3<T> asVec3() const;

        /**
         * @brief Get the Vec1 repr
         */
        Vector4<T> asVec4() const;

        /**
         * @brief Cast to a Vector of type T2
         */
        template <typename T2> Vector<T2, N> cast() const
        {
            return as<T2, N>();
        }

        /**
         * @brief Addition a Vector to another
         */
        Vector<T, N> operator+(const Vector<T, N>& other) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice] + other[vertice];
            return result;
        }

        /**
         * @brief Subtraction a Vector to another
         */
        Vector<T, N> operator-(const Vector<T, N>& other) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice] - other[vertice];
            return result;
        }

        /**
         * @brief Multiplication a Vector to another
         */
        Vector<T, N> operator*(const Vector<T, N>& other) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice] * other[vertice];
            return result;
        }

        /**
         * @brief Division a Vector to another
         */
        Vector<T, N> operator/(const Vector<T, N>& other) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice] / other[vertice];
            return result;
        }

        /**
         * @brief Addition a Vector to another
         */
        Vector<T, N>& operator+=(const Vector<T, N>& other)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] += other[vertice];
            return *this;
        }

        /**
         * @brief Subtraction a Vector to another
         */
        Vector<T, N>& operator-=(const Vector<T, N>& other)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] -= other[vertice];
            return *this;
        }

        /**
         * @brief Multiplication a Vector to another
         */
        Vector<T, N>& operator*=(const Vector<T, N>& other)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] *= other[vertice];
            return *this;
        }

        /**
         * @brief Division a Vector to another
         */
        Vector<T, N>& operator/=(const Vector<T, N>& other)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] /= other[vertice];
            return *this;
        }

        /**
         * @brief Addition a Vector to a ratio
         */
        Vector<T, N> operator+(const T& ratio) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice] + ratio;
            return result;
        }

        /**
         * @brief Subtraction a Vector to a ratio
         */
        Vector<T, N> operator-(const T& ratio) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice] - ratio;
            return result;
        }

        /**
         * @brief Multiplication a Vector to a ratio
         */
        Vector<T, N> operator*(const T& ratio) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice] * ratio;
            return result;
        }

        /**
         * @brief Division a Vector to a ratio
         */
        Vector<T, N> operator/(const T& ratio) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice] = m_vertices[vertice] / ratio;
            return result;
        }

        /**
         * @brief Addition a Vector to a ratio
         */
        Vector<T, N>& operator+=(const T& ratio)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] += ratio;
            return *this;
        }

        /**
         * @brief Subtraction a Vector to a ratio
         */
        Vector<T, N>& operator-=(const T& ratio)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] -= ratio;
            return *this;
        }

        /**
         * @brief Multiplication a Vector to a ratio
         */
        Vector<T, N>& operator*=(const T& ratio)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] *= ratio;
            return *this;
        }

        /**
         * @brief Division a Vector to a ratio
         */
        Vector<T, N>& operator/=(const T& ratio)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] /= ratio;
            return *this;
        }

        /**
         * @brief Invert vector
         */
        Vector<T, N>& operator-()
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                m_vertices[vertice] = -m_vertices[vertice];
            return *this;
        }

        /**
         * @brief Get the squared length of the Vector
         */
        T squaredLength() const
        {
            T result = 0;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result += m_vertices[vertice] * m_vertices[vertice];
            return result;
        }

        /**
         * @brief Get the length of the Vector
         */
        T length() const { return sqrt(squaredLength()); }

        /**
         * @brief Normalize the Vector
         */
        void normalize()
        {
            T len = length();
            if (len > 0) {
                for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                    m_vertices[vertice] /= len;
            }
        }

        /**
         * @brief Get the normalized Vector
         */
        Vector<T, N> normalized() const
        {
            Vector<T, N> result = *this;
            result.normalize();
            return result;
        }

        /**
         * @brief Get the dot product of the Vector
         */
        T dot(const Vector<T, N>& other) const
        {
            T result = 0;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result += m_vertices[vertice] * other[vertice];
            return result;
        }

        /**
         * @brief Get the cross product of the Vector
         */
        Vector<T, N> cross(const Vector<T, N>& other) const
        {
            Vector<T, N> result;
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                result[vertice]
                    = m_vertices[(vertice + 1) % N] * other[(vertice + 2) % N]
                    - m_vertices[(vertice + 2) % N] * other[(vertice + 1) % N];
            return result;
        }

        /**
         * @brief Get the angle between the Vector and another
         */
        T angle(const Vector<T, N>& other) const
        {
            return acos(dot(other) / (length() * other.length()));
        }

        /**
         * @brief Get the distance between the Vector and another
         */
        T distance(const Vector<T, N>& other) const
        {
            return (*this - other).length();
        }

        /**
         * @brief Get the squared distance between the Vector and another
         */
        T squaredDistance(const Vector<T, N>& other) const
        {
            return (*this - other).squaredLength();
        }

        /**
         * @brief Get the maximum value of the Vector
         */
        T max() const
        {
            T result = m_vertices[0];
            for (vector_size_type_t vertice = 1; vertice < N; ++vertice)
                result = max(result, m_vertices[vertice]);
            return result;
        }

        /**
         * @brief Get the minimum value of the Vector
         */
        T min() const
        {
            T result = m_vertices[0];
            for (vector_size_type_t vertice = 1; vertice < N; ++vertice)
                result = min(result, m_vertices[vertice]);
            return result;
        }

        /**
         * @brief Get the maximum abs value of the Vector
         */
        T maxAbs() const
        {
            T result = abs(m_vertices[0]);
            for (vector_size_type_t vertice = 1; vertice < N; ++vertice)
                result = max(result, std::abs(m_vertices[vertice]));
            return result;
        }

        /**
         * @brief Get the minimum abs value of the Vector
         */
        T minAbs() const
        {
            T result = abs(m_vertices[0]);
            for (vector_size_type_t vertice = 1; vertice < N; ++vertice)
                result = min(result, abs(m_vertices[vertice]));
            return result;
        }

        /**
         * @brief Linear interpolation between two Vector of the same size
         */
        static Vector<T, N> s_lerp(const Vector<T, N>& a, const Vector<T, N>& b,
                                   T t)
        {
            return a * (1 - t) + b * t;
        }

        /**
         * @brief Linear interpolation between self and another Vector of the
         * same size
         */
        Vector<T, N>& lerp(const Vector<T, N>& other, T t)
        {
            return *this = s_lerp(*this, other, t);
        }

        /**
         * @brief Compare two vectors of the same type/size
         *
         */
        bool operator==(const Vector<T, N>& other)
        {
            for (vector_size_type_t vertice = 0; vertice < N; ++vertice)
                if (m_vertices[vertice] != other[vertice])
                    return false;
            return true;
        }

        /**
         * @brief Compare two vectors of the same type/size
         *
         */
        bool operator!=(const Vector<T, N>& other) { return !(*this == other); }
    };

    template <typename T> struct Vector2 : public Vector<T, 2> {
    public:
        T& x = this->m_vertices[0];
        T& y = this->m_vertices[1];

        /**
         * @brief Construct a new Vector2 object
         *
         * @param x
         * @param y
         */
        Vector2(const T& x, const T& y)
        {
            this->x = x;
            this->y = y;
        }

        /**
         * @brief Basic constructor + destructor
         */
        INFERDUM_DEFAULT_CONSTRUCTIBLE(Vector2);

        /**
         * @brief Copy constructor for Vector2
         */
        Vector2<T>& operator=(const Vector2<T>& other)
        {
            this->x = other.x;
            this->y = other.y;
            return *this;
        }

        /**
         * @brief Lerp between two Vector2
         */
        static Vector2<T> s_lerp(const Vector2<T>& a, const Vector2<T>& b, T t)
        {
            return Vector<T, 2>::s_lerp(a, b, t).asVec2();
        }

        /**
         * @brief Lerp between self and another Vector2
         */
        Vector2<T>& lerp(const Vector2<T>& other, T t)
        {
            return *this = Vector2<T>::s_lerp(*this, other, t);
        }
    };

    template <typename T> class Vector3 : public Vector<T, 3> {
    public:
        T& x = this->m_vertices[0];
        T& y = this->m_vertices[1];
        T& z = this->m_vertices[2];

        /**
         * @brief Construct a new Vector3 object
         *
         * @param x
         * @param y
         * @param z
         */
        Vector3(const T& x, const T& y, const T& z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        /**
         * @brief Basic constructor + destructor
         */
        INFERDUM_DEFAULT_CONSTRUCTIBLE(Vector3);

        /**
         * @brief Copy constructor for Vector3
         */
        Vector3<T>& operator=(const Vector3<T>& other)
        {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            return *this;
        }

        /**
         * @brief Lerp between two Vector3
         */
        static Vector3<T> s_lerp(const Vector3<T>& a, const Vector3<T>& b, T t)
        {
            return Vector<T, 3>::s_lerp(a, b, t).asVec3();
        }

        /**
         * @brief Lerp between self and another Vector2
         */
        Vector3<T>& lerp(const Vector3<T>& other, T t)
        {
            return *this = Vector3<T>::s_lerp(*this, other, t);
        }
    };

    template <typename T> class Vector4 : public Vector<T, 4> {
    public:
        T& x = this->m_vertices[0];
        T& y = this->m_vertices[1];
        T& z = this->m_vertices[2];
        T& w = this->m_vertices[3];

        /**
         * @brief Construct a new Vector4 object
         *
         * @param x
         * @param y
         * @param z
         * @param w
         */
        Vector4(const T& x, const T& y, const T& z, const T& w)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        /**
         * @brief Basic constructor + destructor
         */
        INFERDUM_DEFAULT_CONSTRUCTIBLE(Vector4);

        /**
         * @brief Copy constructor for Vector4
         */
        Vector4<T>& operator=(const Vector4<T>& other)
        {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            this->w = other.w;
            return *this;
        }

        /**
         * @brief Lerp between two Vector3
         */
        static Vector4<T> s_lerp(const Vector4<T>& a, const Vector4<T>& b, T t)
        {
            return Vector<T, 4>::s_lerp(a, b, t).asVec4();
        }

        /**
         * @brief Lerp between self and another Vector2
         */
        Vector4<T>& lerp(const Vector4<T>& other, T t)
        {
            return *this = Vector4<T>::s_lerp(*this, other, t);
        }
    };

    template <typename T, vector_size_type_t N>
    Vector2<T> Vector<T, N>::asVec2() const
    {
        return Vector2<T>(m_vertices[0], m_vertices[1]);
    }

    template <typename T, vector_size_type_t N>
    Vector3<T> Vector<T, N>::asVec3() const
    {
        if constexpr (N == 2)
            return Vector3<T>(m_vertices[0], m_vertices[1], 0);
        else
            return Vector3<T>(m_vertices[0], m_vertices[1], m_vertices[2]);
    }

    template <typename T, vector_size_type_t N>
    Vector4<T> Vector<T, N>::asVec4() const
    {
        if constexpr (N == 2)
            return Vector4<T>(m_vertices[0], m_vertices[1], 0, 0);
        else if constexpr (N == 3)
            return Vector4<T>(m_vertices[0], m_vertices[1], m_vertices[2], 0);
        else
            return Vector4<T>(m_vertices[0], m_vertices[1], m_vertices[2],
                              m_vertices[3]);
    }

    using Vector2i = Vector2<i32>;
    using Vector2f = Vector2<f32>;
    using Vector2d = Vector2<f64>;
    using Vector2u = Vector2<u32>;
    using Vector3i = Vector3<i32>;
    using Vector3f = Vector3<f32>;
    using Vector3d = Vector3<f64>;
    using Vector3u = Vector3<u32>;
    using Vector4i = Vector4<i32>;
    using Vector4f = Vector4<f32>;
    using Vector4d = Vector4<f64>;
    using Vector4u = Vector4<u32>;
}