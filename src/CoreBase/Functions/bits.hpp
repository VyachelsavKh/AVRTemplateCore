#ifndef __CORE_BASE_FUNCTIONS_BITS_HELPER_HPP__
#define __CORE_BASE_FUNCTIONS_BITS_HELPER_HPP__

#include "CoreBase/Functions/typeCheckers.hpp"

// Функция для получения значения с битом на установленным переданной позиции
constexpr uint64_t bit(uint8_t pos) { return uint64_t(1) << (pos); }

// Функция для получения значения с битами установленными на переданных позициях
template<typename... Args>
constexpr uint64_t bits(Args... positions)
{
    static_assert((_check_is_integer<Args>::value && ...), 
                    "Переданные позиции должны быть целыми числами");
	return (bit(positions) | ...);
}

// Функция для получения значения с битами установленными на переданных позициях
template<>
constexpr uint64_t bits() { return 0; }

// Функция для получения значения с битами установленными на всех позициях кроме переданных
template<typename... Args>
constexpr uint64_t other_bits(Args... positions) { return ~bits(positions...); }

// Функция для получения значения с битами установленными на всех позициях кроме переданных
template<>
constexpr uint64_t other_bits() { return ~bits(); }

// Функция для чтения битов на переданых позициях
template<typename T, typename... Args>
inline uint64_t get_bits(const T& src, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    return src & static_cast<T>(bits(positions...)); 
}

// Функция для чтения остальных битов кроме переданных позиций
template<typename T, typename... Args>
inline uint64_t get_other_bits(const T& src, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    return src & static_cast<T>(other_bits(positions...)); 
}

// Функция для установки битов на переданых позициях
template<typename T, typename... Args>
inline void set_bits(T& dst, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst |= static_cast<T>(bits(positions...)); 
}

// Функция для установки остальных битов кроме переданных позиций
template<typename T, typename... Args>
inline void set_other_bits(T& dst, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst |= static_cast<T>(other_bits(positions...)); 
}

// Функция для инвертирования битов на переданых позициях
template<typename T, typename... Args>
inline void toggle_bits(T& dst, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst ^= static_cast<T>(bits(positions...));
}

// Функция для инвертирования остальных битов кроме переданных позиций
template<typename T, typename... Args>
inline void toggle_other_bits(T& dst, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst ^= static_cast<T>(other_bits(positions...));
}

// Функция для очистки битов на переданых позициях
template<typename T, typename... Args>
inline void clear_bits(T& dst, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst &= static_cast<T>(other_bits(positions...));
}

// Функция для очистки остальных битов кроме переданных позиций
template<typename T, typename... Args>
inline void clear_other_bits(T& dst, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst &= static_cast<T>(bits(positions...));
}

#endif