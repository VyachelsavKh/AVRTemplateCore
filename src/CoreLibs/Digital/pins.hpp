#ifndef __CORE_LIBS_DIGITAL_PINS_HPP__
#define __CORE_LIBS_DIGITAL_PINS_HPP__

#ifdef PA0
    #undef PA0
#endif
#ifdef PA1
    #undef PA1
#endif
#ifdef PA2
    #undef PA2
#endif
#ifdef PA3
    #undef PA3
#endif
#ifdef PA4
    #undef PA4
#endif
#ifdef PA5
    #undef PA5
#endif
#ifdef PA6
    #undef PA6
#endif
#ifdef PA7
    #undef PA7
#endif

#ifdef PB0
    #undef PB0
#endif
#ifdef PB1
    #undef PB1
#endif
#ifdef PB2
    #undef PB2
#endif
#ifdef PB3
    #undef PB3
#endif
#ifdef PB4
    #undef PB4
#endif
#ifdef PB5
    #undef PB5
#endif
#ifdef PB6
    #undef PB6
#endif
#ifdef PB7
    #undef PB7
#endif

#ifdef PC0
    #undef PC0
#endif
#ifdef PC1
    #undef PC1
#endif
#ifdef PC2
    #undef PC2
#endif
#ifdef PC3
    #undef PC3
#endif
#ifdef PC4
    #undef PC4
#endif
#ifdef PC5
    #undef PC5
#endif
#ifdef PC6
    #undef PC6
#endif
#ifdef PC7
    #undef PC7
#endif

#ifdef PD0
    #undef PD0
#endif
#ifdef PD1
    #undef PD1
#endif
#ifdef PD2
    #undef PD2
#endif
#ifdef PD3
    #undef PD3
#endif
#ifdef PD4
    #undef PD4
#endif
#ifdef PD5
    #undef PD5
#endif
#ifdef PD6
    #undef PD6
#endif
#ifdef PD7
    #undef PD7
#endif

#ifdef PE0
    #undef PE0
#endif
#ifdef PE1
    #undef PE1
#endif
#ifdef PE2
    #undef PE2
#endif
#ifdef PE3
    #undef PE3
#endif
#ifdef PE4
    #undef PE4
#endif
#ifdef PE5
    #undef PE5
#endif
#ifdef PE6
    #undef PE6
#endif
#ifdef PE7
    #undef PE7
#endif

#ifdef PF0
    #undef PF0
#endif
#ifdef PF1
    #undef PF1
#endif
#ifdef PF2
    #undef PF2
#endif
#ifdef PF3
    #undef PF3
#endif
#ifdef PF4
    #undef PF4
#endif
#ifdef PF5
    #undef PF5
#endif
#ifdef PF6
    #undef PF6
#endif
#ifdef PF7
    #undef PF7
#endif

#ifdef PG0
    #undef PG0
#endif
#ifdef PG1
    #undef PG1
#endif
#ifdef PG2
    #undef PG2
#endif
#ifdef PG3
    #undef PG3
#endif
#ifdef PG4
    #undef PG4
#endif
#ifdef PG5
    #undef PG5
#endif
#ifdef PG6
    #undef PG6
#endif
#ifdef PG7
    #undef PG7
#endif

#ifdef PH0
    #undef PH0
#endif
#ifdef PH1
    #undef PH1
#endif
#ifdef PH2
    #undef PH2
#endif
#ifdef PH3
    #undef PH3
#endif
#ifdef PH4
    #undef PH4
#endif
#ifdef PH5
    #undef PH5
#endif
#ifdef PH6
    #undef PH6
#endif
#ifdef PH7
    #undef PH7
#endif

#ifdef PJ0
    #undef PJ0
#endif
#ifdef PJ1
    #undef PJ1
#endif
#ifdef PJ2
    #undef PJ2
#endif
#ifdef PJ3
    #undef PJ3
#endif
#ifdef PJ4
    #undef PJ4
#endif
#ifdef PJ5
    #undef PJ5
#endif
#ifdef PJ6
    #undef PJ6
#endif
#ifdef PJ7
    #undef PJ7
#endif

#ifdef PK0
    #undef PK0
#endif
#ifdef PK1
    #undef PK1
#endif
#ifdef PK2
    #undef PK2
#endif
#ifdef PK3
    #undef PK3
#endif
#ifdef PK4
    #undef PK4
#endif
#ifdef PK5
    #undef PK5
#endif
#ifdef PK6
    #undef PK6
#endif
#ifdef PK7
    #undef PK7
#endif

#ifdef PL0
    #undef PL0
#endif
#ifdef PL1
    #undef PL1
#endif
#ifdef PL2
    #undef PL2
#endif
#ifdef PL3
    #undef PL3
#endif
#ifdef PL4
    #undef PL4
#endif
#ifdef PL5
    #undef PL5
#endif
#ifdef PL6
    #undef PL6
#endif
#ifdef PL7
    #undef PL7
#endif

#if defined (__AVR_ATmega328P__) || defined (__AVR_ATmega328__)
    #include "CoreLibs/Digital/Pins/atmega328p.hpp"
#elif defined (__AVR_ATmega2560__)
    #include "CoreLibs/Digital/Pins/atmega2560.hpp"
#else
    #warning "device type not defined"
#endif

#endif