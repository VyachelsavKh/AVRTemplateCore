#ifndef __CORE_BASE_FUNCTIONS_NUMBERS_HELPER__
#define __CORE_BASE_FUNCTIONS_NUMBERS_HELPER__

#include "CoreBase/Functions/typeCheckers.hpp"

// Ограничить значение value в диапазоне [min, max]
template<class T>
constexpr T constrain(T value, T min, T max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

// Перевести значение value 
// из диапазона [min1, max1] 
// в значение из диапазона [min2, max2]
template<class T>
constexpr T map(T value, T min1, T max1, T min2, T max2)
{
    return (value - min1) / (max1 - min1) * (max2 - min2) + min2;
}

template <typename T>
inline constexpr T min(T first) { return first; }

template <typename T, typename... Args>
inline constexpr T min(T first, Args... args) 
{
    constexpr bool all_same = (true && ... && _check_is_same<T, Args>::value);
    static_assert(all_same, "Все аргументы должны быть одного типа");

    T minValue = first;
    T values[] = {args...};

    for (T value : values) 
        if (value < minValue) 
            minValue = value;
    
    return minValue;
}

template <typename T>
inline constexpr T max(T first) { return first; }

template <typename T, typename... Args>
inline constexpr T max(T first, Args... args) 
{
    constexpr bool all_same = (true && ... && _check_is_same<T, Args>::value);
    static_assert(all_same, "Все аргументы должны быть одного типа");
    
    T maxValue = first;
    T values[] = {args...};

    for (T value : values)
        if (value > maxValue)
            maxValue = value;

    return maxValue;
}

#endif