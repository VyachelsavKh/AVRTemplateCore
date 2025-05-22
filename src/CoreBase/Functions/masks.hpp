#ifndef __CORE_BASE_FUNCTIONS_MASKS_HELPER_HPP__
#define __CORE_BASE_FUNCTIONS_MASKS_HELPER_HPP__

#include "CoreBase/Functions/typeCheckers.hpp"

// Функция для получения значения с битами установленными по позициям покрытыми маскам
template<typename... Args> 
consteval uint64_t masks(Args... _masks)
{
    static_assert((_check_is_integer<Args>::value && ...), 
                    "Переданные маски должны быть целыми числами");
    return (_masks | ...);
}
// Функция для получения значения с битами установленными по позициям покрытыми маскам
template<> 
consteval uint64_t masks() { return 0; }

// Функция для получения значения с битами установленными по позициям не покрытыми масками
template<typename... Args> 
consteval uint64_t other_masks(Args... _masks) { return ~masks(_masks...); }
// Функция для получения значения с битами установленными по позициям не покрытыми масками
template<> 
consteval uint64_t other_masks() { return 0; }

// Функция для чтения битов на переданых позициях
template<typename T, typename... Args>
inline uint64_t get_masks(const T& src, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    return src & static_cast<T>(masks(positions...)); 
}

// Функция для чтения остальных битов кроме переданных позиций
template<typename T, typename... Args>
inline uint64_t get_other_masks(const T& src, Args... positions) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    return src & static_cast<T>(other_masks(positions...)); 
}

// Функция для установки битов на переданых позициях
template<typename T, typename... Args>
inline void set_masks(T& dst, Args... _masks) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst |= static_cast<T>(masks(_masks...)); 
}

// Функция для установки остальных битов кроме переданных позиций
template<typename T, typename... Args>
inline void set_other_masks(T& dst, Args... _masks) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst |= static_cast<T>(other_masks(_masks...)); 
}

// Функция для инвертирования битов на переданых позициях
template<typename T, typename... Args>
inline void toggle_masks(T& dst, Args... _masks) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst ^= static_cast<T>(masks(_masks...));
}

// Функция для инвертирования остальных битов кроме переданных позиций
template<typename T, typename... Args>
inline void toggle_other_masks(T& dst, Args... _masks) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst ^= static_cast<T>(other_masks(_masks...));
}

// Функция для очистки битов на переданых позициях
template<typename T, typename... Args>
inline void clear_masks(T& dst, Args... _masks) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst &= static_cast<T>(other_masks(_masks...));
}

// Функция для очистки остальных битов кроме переданных позиций
template<typename T, typename... Args>
inline void clear_other_masks(T& dst, Args... _masks) 
{
    static_assert(_check_is_integer<T>::value || 
                    _check_is_volatile_integer<T>::value,
                    "Переданная переменная не ссылается на целое число");
    dst &= static_cast<T>(masks(_masks...));
}

#endif