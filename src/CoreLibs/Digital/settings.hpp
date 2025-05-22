#ifndef __CORE_LIBS_DIGITAL_SETTINGS_HPP__
#define __CORE_LIBS_DIGITAL_SETTINGS_HPP__

#include "CoreBase/io.hpp"

#include "CoreBase/Functions/base.hpp"

enum class DIGITAL_PIN_MODE
{
    INPUT,
    OUTPUT,
    INPUT_PULLUP,
};

constexpr DIGITAL_PIN_MODE INPUT = DIGITAL_PIN_MODE::INPUT;
constexpr DIGITAL_PIN_MODE OUTPUT = DIGITAL_PIN_MODE::OUTPUT;
constexpr DIGITAL_PIN_MODE INPUT_PULLUP = DIGITAL_PIN_MODE::INPUT_PULLUP;

enum class DIGITAL_PIN_VALUE
{
    LOW,
    HIGH,
    TOGGLE,
};

constexpr DIGITAL_PIN_VALUE LOW = DIGITAL_PIN_VALUE::LOW;
constexpr DIGITAL_PIN_VALUE HIGH = DIGITAL_PIN_VALUE::HIGH;
constexpr DIGITAL_PIN_VALUE TOGGLE = DIGITAL_PIN_VALUE::TOGGLE;

struct DIGITAL_PIN_SETTING
{
    REGISTER_UPDATE DDR_update;
    REGISTER_UPDATE PORT_update;

    DIGITAL_BUS_ID bus_id;

    consteval DIGITAL_PIN_SETTING(DIGITAL_BUS_ID _id = 0) : bus_id(_id) { }

    consteval DIGITAL_PIN_SETTING& operator|=(const DIGITAL_PIN_SETTING& other)
    {
        if (bus_id == other.bus_id) 
        {
            DDR_update |= other.DDR_update;
            PORT_update |= other.PORT_update;
        }

        return *this;
    }

    consteval DIGITAL_PIN_SETTING operator|(const DIGITAL_PIN_SETTING& other) const
    {
        DIGITAL_PIN_SETTING result = *this;

        return result |= other;
    }
};

struct DIGITAL_PIN_MODE_SETTING
{
    DIGITAL_PIN_SETTING INPUT;
    DIGITAL_PIN_SETTING OUTPUT;
    DIGITAL_PIN_SETTING INPUT_PULLUP;

    consteval DIGITAL_PIN_MODE_SETTING(DIGITAL_BUS_ID bus_id = 0, uint8_t pin = 0)
    {
        INPUT.bus_id = bus_id;
        INPUT.DDR_update.clear = bit(pin);

        OUTPUT.bus_id = bus_id;
        OUTPUT.DDR_update.set = bit(pin);

        INPUT_PULLUP.bus_id = bus_id;
        INPUT_PULLUP.DDR_update.clear = bit(pin);
        INPUT_PULLUP.PORT_update.set = bit(pin);
    }
};

struct DIGITAL_PIN_VALUE_SETTING
{
    DIGITAL_PIN_SETTING LOW;
    DIGITAL_PIN_SETTING HIGH;
    DIGITAL_PIN_SETTING TOGGLE;

    consteval DIGITAL_PIN_VALUE_SETTING(DIGITAL_BUS_ID bus_id = 0, uint8_t pin = 0)
    {
        LOW.bus_id = bus_id;
        LOW.PORT_update.clear = bit(pin);

        HIGH.bus_id = bus_id;
        HIGH.PORT_update.set = bit(pin);

        TOGGLE.bus_id = bus_id;
        TOGGLE.PORT_update.toggle = bit(pin);
    }
};

#endif