#pragma once

#include <cstddef>
#include <cstdint>

#define INFERDUM_DEFAULT_CONSTRUCTIBLE(type)                                   \
    type()  = default;                                                         \
    ~type() = default

#define INFERDUM_CANONICAL_FORM(type)                                          \
    type(const type&) = default;                                               \
    type& operator=(const type&) = default;                                    \
    type(type&&)                 = default;                                    \
    type& operator=(type&&) = default

#define INFERDUM_CANONICAL_FORM_TEMPLATE(type, ...)                            \
    type(const type<__VA_ARGS__>&) = default;                                  \
    type& operator=(const type<__VA_ARGS__>&) = default;                       \
    type(type<__VA_ARGS__>&&)                 = default;                       \
    type& operator=(type<__VA_ARGS__>&&) = default

#define INFERDUM_FULLY_DEFAULT_CANNONICAL(type)                                \
    INFERDUM_DEFAULT_CONSTRUCTIBLE(type);                                      \
    INFERDUM_CANONICAL_FORM(type)

#define INFERDUM_FULLY_DEFAULT_CANNONICAL_TEMPLATE(type, ...)                  \
    INFERDUM_DEFAULT_CONSTRUCTIBLE(type);                                      \
    INFERDUM_CANONICAL_FORM_TEMPLATE(type, __VA_ARGS__)

#define INFERDUM_ASSERT_GOTO(assertion, label)                                 \
    {                                                                          \
        if ((assertion) == false) {                                            \
            goto label;                                                        \
        }                                                                      \
    }

#define INFERDUM_MEMBER_FUNC_BUILDER(class_type, value_type, s, name) \
    class_type& name(const value_type& name) \
    { \
        s.name = name; \
        return *this; \
    }

namespace inferdum {
    using i8    = std::int8_t;
    using i16   = std::int16_t;
    using i32   = std::int32_t;
    using i64   = std::int64_t;
    using u8    = std::uint8_t;
    using u16   = std::uint16_t;
    using u32   = std::uint32_t;
    using u64   = std::uint64_t;
    using f32   = float;
    using f64   = double;
    using f128  = long double;
    using usize = std::size_t;
    using isize = std::ptrdiff_t;
    using byte  = std::uint8_t;
} // namespace inferdum