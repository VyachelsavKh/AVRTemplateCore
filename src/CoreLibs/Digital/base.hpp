#ifndef __CORE_LIBS_DIGITAL_BASE_HPP__
#define __CORE_LIBS_DIGITAL_BASE_HPP__

#include "CoreLibs/Digital/settings.hpp"
#include "CoreBase/Classes/array.hpp"

namespace __DigitalInner
{
    template<DIGITAL_BUS_ID bus, DIGITAL_PIN_SETTING setting>
    inline void updateSetting()
    {
        DIGITAL_BUS_REGS& bus_regs = GET_DIGITAL_BUS_REGS<bus>();

        bus_regs.DDR.update_setting<setting.DDR_update>();
        bus_regs.PORT.update_setting<setting.PORT_update>();
    }

    template<DIGITAL_BUS_ID bus, DIGITAL_PIN_SETTING setting>
    inline void setSetting()
    {
        DIGITAL_BUS_REGS& bus_regs = GET_DIGITAL_BUS_REGS<bus>();

        bus_regs.DDR.set_setting<setting.DDR_update>();
        bus_regs.PORT.set_setting<setting.PORT_update>();
    }

    template <DIGITAL_PIN_SETTING begin, DIGITAL_PIN_SETTING... rest>
    static consteval DIGITAL_PIN_SETTING combineSettings() {
        return (begin | ... | rest);
    }

    template<uint8_t bus_id, DIGITAL_PIN_SETTING... settings>
    inline void updateSettings()
    {
        constexpr auto setting = combineSettings<DIGITAL_PIN_SETTING(bus_id), settings...>();

        updateSetting<bus_id, setting>();

        if constexpr (bus_id + 1 < DIGITAL_BUS_COUNT)
            updateSettings<bus_id + uint8_t(1), settings...>();
    }

    template<uint8_t bus_id, DIGITAL_PIN_SETTING... settings>
    inline void setSettings()
    {
        constexpr auto setting = combineSettings<DIGITAL_PIN_SETTING(bus_id), settings...>();

        setSetting<bus_id, setting>();

        if constexpr (bus_id + 1 < DIGITAL_BUS_COUNT)
            setSettings<bus_id + uint8_t(1), settings...>();
    }
}

template<DIGITAL_BUS_ID _bus, uint8_t _pin>
struct DigitalPin
{
    static constexpr DIGITAL_BUS_ID bus = _bus;
    static constexpr uint8_t pin = _pin;

    static constexpr DIGITAL_PIN_MODE_SETTING  MODE  = {bus, pin};
    static constexpr DIGITAL_PIN_VALUE_SETTING VALUE = {bus, pin};

    template<DIGITAL_PIN_MODE mode>
    static inline void updateMode()
    {
        DIGITAL_BUS_REGS& bus_regs = GET_DIGITAL_BUS_REGS<bus>();

        switch (mode)
        {
        case INPUT:
            bus_regs.DDR.clear(bit(pin));
            return;
        case OUTPUT:
            bus_regs.DDR.set(bit(pin));
            return;
        case INPUT_PULLUP:
            bus_regs.DDR.clear(bit(pin));
            bus_regs.PORT.set(bit(pin));
            return;
        }
    }
    
    template<DIGITAL_PIN_VALUE value>
    static inline void updateValue()
    {
        DIGITAL_BUS_REGS& bus_regs = GET_DIGITAL_BUS_REGS<bus>();

        switch (value)
        {
        case LOW:
            bus_regs.PORT.clear(bit(pin));
            return;
        case HIGH:
            bus_regs.PORT.set(bit(pin));
            return;
        case TOGGLE:
            bus_regs.PORT.toggle(bit(pin));
            return;
        }
    }
};

struct DigitalClass
{
    template<DIGITAL_PIN_SETTING... settings>
    static inline void updateSettings()
    {
        __DigitalInner::updateSettings<0, settings...>();
    }

    template<DIGITAL_PIN_SETTING... settings>
    static inline void setSettings()
    {
        __DigitalInner::setSettings<0, settings...>();
    }
};

constexpr DigitalClass Digital;

#endif