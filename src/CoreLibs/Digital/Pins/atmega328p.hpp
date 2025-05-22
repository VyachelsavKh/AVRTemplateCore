#ifndef __CORE_LIBS_DIGITAL_PINS_HPP__
    #error "Include CoreLibs/pins.hpp instead of this file."
#endif

#ifndef _MICRO_CORE_DIGITAL_PINS_HPP_
    #define _MICRO_CORE_DIGITAL_PINS_HPP_ "atmega328p.h"
#else
    #error "Attempt to include more than one "CoreLibs/Digital/Pins/atmegaXXX.hpp">" file."
#endif

#ifndef __CORE_LIBS_DIGITAL_PINS_ATMEGA328P_HPP__
#define __CORE_LIBS_DIGITAL_PINS_ATMEGA328P_HPP__

#include "CoreLibs/Digital/base.hpp"

constexpr DigitalPin<DBB, 0> PB0;
constexpr DigitalPin<DBB, 1> PB1;
constexpr DigitalPin<DBB, 2> PB2;
constexpr DigitalPin<DBB, 3> PB3;
constexpr DigitalPin<DBB, 4> PB4;
constexpr DigitalPin<DBB, 5> PB5;

constexpr DigitalPin<DBC, 0> PC0;
constexpr DigitalPin<DBC, 1> PC1;
constexpr DigitalPin<DBC, 2> PC2;
constexpr DigitalPin<DBC, 3> PC3;
constexpr DigitalPin<DBC, 4> PC4;
constexpr DigitalPin<DBC, 5> PC5;
constexpr DigitalPin<DBC, 6> PC6;

constexpr DigitalPin<DBD, 0> PD0;
constexpr DigitalPin<DBD, 1> PD1;
constexpr DigitalPin<DBD, 2> PD2;
constexpr DigitalPin<DBD, 3> PD3;
constexpr DigitalPin<DBD, 4> PD4;
constexpr DigitalPin<DBD, 5> PD5;
constexpr DigitalPin<DBD, 6> PD6;
constexpr DigitalPin<DBD, 7> PD7;

#endif