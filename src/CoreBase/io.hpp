#ifndef __CORE_BASE_IO_HPP__
#define __CORE_BASE_IO_HPP__

#if defined (__AVR_ATmega328P__) || defined (__AVR_ATmega328__)
    #include "CoreBase/IO/iom328p.hpp"
#elif defined (__AVR_ATmega2560__)
    #include "CoreBase/IO/iom2560.hpp"
#else
    #warning "device type not defined"
#endif

#endif