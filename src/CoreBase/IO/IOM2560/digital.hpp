#ifndef __CORE_BASE_IO_IOM2560_HPP__
    #error "Include <avr/io.h> instead of this file."
#endif

#ifndef __CORE_BASE_IO_IOM2560_DIGITAL_HPP__
#define __CORE_BASE_IO_IOM2560_DIGITAL_HPP__

#include "CoreBase/IO/registers.hpp"

#define __HAS_BUSA
#define __HAS_BUSB
#define __HAS_BUSC
#define __HAS_BUSD
#define __HAS_BUSE
#define __HAS_BUSF
#define __HAS_BUSG
#define __HAS_BUSH
#define __HAS_BUSJ
#define __HAS_BUSK
#define __HAS_BUSL

struct DIGITAL_BUS_REGS
{
    REGISTER_8_BIT PIN;
    REGISTER_8_BIT DDR;
    REGISTER_8_BIT PORT;
};

#define __DBR(addr) (*(DIGITAL_BUS_REGS*)(addr))

inline DIGITAL_BUS_REGS& DIGITAL_BUS0 = __DBR(0);

inline DIGITAL_BUS_REGS& DIGITAL_BUSA = __DBR(0x020);
inline DIGITAL_BUS_REGS& DIGITAL_BUSB = __DBR(0x023);
inline DIGITAL_BUS_REGS& DIGITAL_BUSC = __DBR(0x026);
inline DIGITAL_BUS_REGS& DIGITAL_BUSD = __DBR(0x029);
inline DIGITAL_BUS_REGS& DIGITAL_BUSE = __DBR(0x02C);
inline DIGITAL_BUS_REGS& DIGITAL_BUSF = __DBR(0x02F);
inline DIGITAL_BUS_REGS& DIGITAL_BUSG = __DBR(0x032);
inline DIGITAL_BUS_REGS& DIGITAL_BUSH = __DBR(0x100);
inline DIGITAL_BUS_REGS& DIGITAL_BUSJ = __DBR(0x103);
inline DIGITAL_BUS_REGS& DIGITAL_BUSK = __DBR(0x106);
inline DIGITAL_BUS_REGS& DIGITAL_BUSL = __DBR(0x109);

struct DIGITAL_BUS_ID
{
    uint8_t id;

    consteval DIGITAL_BUS_ID(uint8_t _id = 0) : id(_id) {}

    constexpr operator uint8_t() const { return id; }
};

constexpr DIGITAL_BUS_ID DBA = 0;
constexpr DIGITAL_BUS_ID DBB = 1;
constexpr DIGITAL_BUS_ID DBC = 2;
constexpr DIGITAL_BUS_ID DBD = 3;
constexpr DIGITAL_BUS_ID DBE = 4;
constexpr DIGITAL_BUS_ID DBF = 5;
constexpr DIGITAL_BUS_ID DBG = 6;
constexpr DIGITAL_BUS_ID DBH = 7;
constexpr DIGITAL_BUS_ID DBJ = 8;
constexpr DIGITAL_BUS_ID DBK = 9;
constexpr DIGITAL_BUS_ID DBL = 10;

constexpr uint8_t DIGITAL_BUS_COUNT = 11;

template<DIGITAL_BUS_ID bus>
inline DIGITAL_BUS_REGS& GET_DIGITAL_BUS_REGS()
{
    switch (bus)
    {
    case DBA:
        return DIGITAL_BUSA;
    case DBB:
        return DIGITAL_BUSB;
    case DBC:
        return DIGITAL_BUSC;
    case DBD:
        return DIGITAL_BUSD;
    case DBE:
        return DIGITAL_BUSE;
    case DBF:
        return DIGITAL_BUSF;
    case DBG:
        return DIGITAL_BUSG;
    case DBH:
        return DIGITAL_BUSH;
    case DBJ:
        return DIGITAL_BUSJ;
    case DBK:
        return DIGITAL_BUSK;
    case DBL:
        return DIGITAL_BUSL;
    default:
        return DIGITAL_BUS0;
    }
}

#endif