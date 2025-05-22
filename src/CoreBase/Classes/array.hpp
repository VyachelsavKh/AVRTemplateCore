#ifndef __CORE_BASE_CLASSES_ARRAY_HPP__
#define __CORE_BASE_CLASSES_ARRAY_HPP__

#include "stdint.h"

template <typename T, uint8_t capacity>
struct array
{
    T data[capacity];
    
    constexpr T& operator[](uint8_t index) { return data[index]; }
    constexpr const T& operator[](uint8_t index) const { return data[index]; }

    consteval uint8_t size() { return capacity; }
};

#endif