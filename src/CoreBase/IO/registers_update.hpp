#ifndef __CORE_BASE_IO_REGISTERS_UPDATE_HPP__
#define __CORE_BASE_IO_REGISTERS_UPDATE_HPP__

#include <stdint.h>

struct REGISTER_UPDATE
{
    uint8_t set;
    uint8_t clear;
    uint8_t toggle;

    consteval REGISTER_UPDATE()
    {
        set = 0;
        clear = 0;
        toggle = 0;
    }

    consteval REGISTER_UPDATE(uint8_t set_val, uint8_t clear_val, uint8_t toggle_val)
    {
        set = set_val;
        clear = clear_val;
        toggle = toggle_val;
    }

    consteval REGISTER_UPDATE(uint8_t new_val, uint8_t val_mask)
    {
        set = new_val & val_mask;
        clear = (~new_val) & val_mask;
    }

    consteval REGISTER_UPDATE& operator|=(const REGISTER_UPDATE& other)
    {
        set    |= other.set;
        clear  |= other.clear;
        toggle |= other.toggle;

        return *this;
    }

    consteval REGISTER_UPDATE operator|(const REGISTER_UPDATE& other) const
    {
        REGISTER_UPDATE result = *this;

        return result |= other;
    }
};

#endif