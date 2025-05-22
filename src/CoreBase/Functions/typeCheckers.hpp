#ifndef __CORE_BASE_FUNCTIONS_TYPE_CHECHEKERS_HPP__
#define __CORE_BASE_FUNCTIONS_TYPE_CHECHEKERS_HPP__

#include <stdint.h>

template<typename T>
struct _check_is_integer { static constexpr bool value = false; };
template<> struct _check_is_integer<int8_t>   { static constexpr bool value = true; };
template<> struct _check_is_integer<uint8_t>  { static constexpr bool value = true; };
template<> struct _check_is_integer<int16_t>  { static constexpr bool value = true; };
template<> struct _check_is_integer<uint16_t> { static constexpr bool value = true; };
template<> struct _check_is_integer<int32_t>  { static constexpr bool value = true; };
template<> struct _check_is_integer<uint32_t> { static constexpr bool value = true; };
template<> struct _check_is_integer<int64_t>  { static constexpr bool value = true; };
template<> struct _check_is_integer<uint64_t> { static constexpr bool value = true; };

template<typename T>
struct _check_is_volatile_integer { static constexpr bool value = false; };
template<> struct _check_is_volatile_integer<volatile int8_t>   { static constexpr bool value = true; };
template<> struct _check_is_volatile_integer<volatile uint8_t>  { static constexpr bool value = true; };
template<> struct _check_is_volatile_integer<volatile int16_t>  { static constexpr bool value = true; };
template<> struct _check_is_volatile_integer<volatile uint16_t> { static constexpr bool value = true; };
template<> struct _check_is_volatile_integer<volatile int32_t>  { static constexpr bool value = true; };
template<> struct _check_is_volatile_integer<volatile uint32_t> { static constexpr bool value = true; };
template<> struct _check_is_volatile_integer<volatile int64_t>  { static constexpr bool value = true; };
template<> struct _check_is_volatile_integer<volatile uint64_t> { static constexpr bool value = true; };

template <typename T, typename U>
struct _check_is_same { static constexpr bool value = false; };
template <typename T>
struct _check_is_same<T, T> { static constexpr bool value = true; };

#endif