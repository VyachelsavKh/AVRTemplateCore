#ifndef __CORE_BASE_IO_IOM328P_HPP__
    #error "Include <avr/io.h> instead of this file."
#endif

#ifndef __CORE_BASE_IO_IOM328P_DIGITAL_HPP__
#define __CORE_BASE_IO_IOM328P_DIGITAL_HPP__

#include "CoreBase/IO/registers.hpp"

#define __HAS_BUSB
#define __HAS_BUSC
#define __HAS_BUSD

struct DIGITAL_BUS_REGS
{
    REGISTER_8_BIT PIN;
    REGISTER_8_BIT DDR;
    REGISTER_8_BIT PORT;
};

struct DIGITAL_BUS_ID
{
    uint8_t id;

    consteval DIGITAL_BUS_ID(uint8_t _id = 0) : id(_id) {}

    constexpr operator uint8_t() const { return id; }
};

#define _DBR(addr) (*(DIGITAL_BUS_REGS*)(addr))

inline DIGITAL_BUS_REGS& DIGITAL_BUS0 = _DBR(0);
inline DIGITAL_BUS_REGS& DIGITAL_BUSB = _DBR(0x023);
inline DIGITAL_BUS_REGS& DIGITAL_BUSC = _DBR(0x026);
inline DIGITAL_BUS_REGS& DIGITAL_BUSD = _DBR(0x029);

constexpr DIGITAL_BUS_ID DBB = 0;
constexpr DIGITAL_BUS_ID DBC = 1;
constexpr DIGITAL_BUS_ID DBD = 2;

constexpr uint8_t DIGITAL_BUS_COUNT = 3;

template<DIGITAL_BUS_ID bus>
inline DIGITAL_BUS_REGS& GET_DIGITAL_BUS_REGS()
{
    switch (bus)
    {
    case DBB:
        return DIGITAL_BUSB;
    case DBC:
        return DIGITAL_BUSC;
    case DBD:
        return DIGITAL_BUSD;
    default:
        return DIGITAL_BUS0;
    }
}

#endif