#ifndef __CORE_BASE_IO_REGISTERS_HPP__
#define __CORE_BASE_IO_REGISTERS_HPP__

#include "CoreBase/IO/registers_update.hpp"

template<class reg_type>
struct REGISTER
{
    volatile reg_type reg;

    inline operator reg_type() const { return reg; }
    inline REGISTER& operator= (reg_type value) { reg = value;  return *this; }
    inline REGISTER& operator|=(reg_type value) { reg |= value; return *this; }
    inline REGISTER& operator&=(reg_type value) { reg &= value; return *this; }
    inline REGISTER& operator^=(reg_type value) { reg ^= value; return *this; }
    inline REGISTER& set   (reg_type value) { *this |= value;  return *this; }
    inline REGISTER& clear (reg_type value) { *this &= ~value; return *this; }
    inline REGISTER& toggle(reg_type value) { *this ^= value;  return *this; }
};

struct REGISTER_8_BIT : REGISTER<uint8_t>
{
    using REGISTER<uint8_t>::operator=;
    using REGISTER<uint8_t>::operator^=;
    using REGISTER<uint8_t>::operator|=;
    using REGISTER<uint8_t>::operator&=;
    using REGISTER<uint8_t>::set;
    using REGISTER<uint8_t>::clear;
    using REGISTER<uint8_t>::toggle;

    inline REGISTER_8_BIT& set_setting(const REGISTER_UPDATE& upd)
    {
        *this = upd.set;
    
        return *this;
    }

    template<REGISTER_UPDATE upd>
    inline REGISTER_8_BIT& set_setting()
    {
        if constexpr(upd.set)
            *this = upd.set; 
    
        return *this;
    }

    inline REGISTER_8_BIT& update_setting(const REGISTER_UPDATE& upd)
    {
        uint8_t val = *this;

        val |= upd.set;
        val &= ~upd.clear;
        val ^= upd.toggle;
    
        *this = val; 

        return *this;
    }
    
    template<REGISTER_UPDATE upd>
    inline REGISTER_8_BIT& update_setting()
    {
        if constexpr (upd.set | upd.clear | upd.toggle)
        {
            uint8_t val = *this;
    
            val |= upd.set;
            val &= ~upd.clear;
            val ^= upd.toggle;
        
            *this = val; 
        }

        return *this;
    }
};

struct REGISTER_16_BIT : REGISTER<uint16_t>
{
    using REGISTER<uint16_t>::operator=;
    using REGISTER<uint16_t>::operator^=;
    using REGISTER<uint16_t>::operator|=;
    using REGISTER<uint16_t>::operator&=;
    using REGISTER<uint16_t>::set;
    using REGISTER<uint16_t>::clear;
    using REGISTER<uint16_t>::toggle;
};

struct REGISTER_32_BIT : REGISTER<uint32_t>
{
    using REGISTER<uint32_t>::operator=;
    using REGISTER<uint32_t>::operator^=;
    using REGISTER<uint32_t>::operator|=;
    using REGISTER<uint32_t>::operator&=;
    using REGISTER<uint32_t>::set;
    using REGISTER<uint32_t>::clear;
    using REGISTER<uint32_t>::toggle;
};

#endif