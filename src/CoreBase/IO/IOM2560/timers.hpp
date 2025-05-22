#ifndef __CORE_BASE_IO_IOM2560_HPP__
    #error "Include <avr/io.h> instead of this file."
#endif

#ifndef __CORE_BASE_IO_IOM2560_TIMERS_HPP__
#define __CORE_BASE_IO_IOM2560_TIMERS_HPP__

#include "CoreBase/IO/registers.hpp"

#define __HAS_TIMER0
#define __HAS_TIMER1
#define __HAS_TIMER2
#define __HAS_TIMER3
#define __HAS_TIMER4
#define __HAS_TIMER5

#define __TIMER_16_BIT_HAS_C_CHANNEL

struct TIMER_BASE_REGS
{
    REGISTER_8_BIT TCCRA;
    REGISTER_8_BIT TCCRB;
};

struct TIMER_8_BIT_REGS : TIMER_BASE_REGS
{
    REGISTER_8_BIT TCNT;
    REGISTER_8_BIT OCRA;
    REGISTER_8_BIT OCRB;
};

#define __T8R(addr) (*(TIMER_8_BIT_REGS*)(addr))

struct TIMER_16_BIT_REGS : TIMER_BASE_REGS
{
    REGISTER_8_BIT  TCCRC;
    const uint8_t   RESERVED;
    REGISTER_16_BIT TCNT;
    REGISTER_16_BIT ICR;
    REGISTER_16_BIT OCRA;
    REGISTER_16_BIT OCRB;
    REGISTER_16_BIT OCRC;
};

#define __T16R(addr) (*(TIMER_16_BIT_REGS*)(addr))

inline TIMER_8_BIT_REGS&  TIMERN8  =  __T8R(0);
inline TIMER_16_BIT_REGS& TIMERN16 = __T16R(0);

inline TIMER_8_BIT_REGS&  TIMER0 =  __T8R(0x044);
inline TIMER_16_BIT_REGS& TIMER1 = __T16R(0x080);
inline TIMER_8_BIT_REGS&  TIMER2 =  __T8R(0x0B0);
inline TIMER_16_BIT_REGS& TIMER3 = __T16R(0x090);
inline TIMER_16_BIT_REGS& TIMER4 = __T16R(0x0A0);
inline TIMER_16_BIT_REGS& TIMER5 = __T16R(0x120);

enum class TIMER_RESOLUTION
{
    TM_8_BIT,
    TM_16_BIT,
};

template<TIMER_RESOLUTION resolution>
struct TIMER_ID
{
    static constexpr TIMER_RESOLUTION res = resolution;
    uint8_t num;

    constexpr TIMER_ID(uint8_t number) : num(number) {}

    constexpr operator uint8_t() const { return num; }
    constexpr operator TIMER_RESOLUTION() const { return res; }
};

constexpr TIMER_RESOLUTION TM_8_BIT = TIMER_RESOLUTION::TM_8_BIT;
constexpr TIMER_RESOLUTION TM_16_BIT = TIMER_RESOLUTION::TM_16_BIT;

constexpr TIMER_ID<TM_8_BIT>  TM0 = 0;
constexpr TIMER_ID<TM_16_BIT> TM1 = 1;
constexpr TIMER_ID<TM_8_BIT>  TM2 = 2;
constexpr TIMER_ID<TM_16_BIT> TM3 = 3;
constexpr TIMER_ID<TM_16_BIT> TM4 = 4;
constexpr TIMER_ID<TM_16_BIT> TM5 = 5;

constexpr uint8_t TIMERS_COUNT = 6;

template<uint8_t num>
constexpr inline TIMER_8_BIT_REGS& GET_TIMER_8_BIT_REGS()
{
    switch (num)
    {
    case TM0:
        return TIMER0;
    case TM2:
        return TIMER2;
    default:
        return TIMERN8;
    }
}

template<uint8_t num>
constexpr inline TIMER_16_BIT_REGS& GET_TIMER_16_BIT_REGS()
{
    switch (num)
    {
    case TM1:
        return TIMER1;
    case TM3:
        return TIMER3;
    case TM4:
        return TIMER4;
    case TM5:
        return TIMER5;
    default:
        return TIMERN16;
    }
}

template<TIMER_ID id>
constexpr inline auto& GET_TIMER_REGS()
{
    if constexpr (id.res == TM_8_BIT)
        return GET_TIMER_8_BIT_REGS<id>();
    else
        return GET_TIMER_16_BIT_REGS<id>();
}

#endif