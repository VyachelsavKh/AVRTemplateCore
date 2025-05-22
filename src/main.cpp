#include "avr/io.h"
#include "util/delay.h"
#include "avr/interrupt.h"

#include "CoreBase/io.hpp"

#include "CoreLibs/Digital/base.hpp"
#include "CoreLibs/Digital/pins.hpp"

PINA

int main()
{
    // Digital.updateSettings<
    //     PB0.MODE.INPUT//,
    //     //PA1.MODE.INPUT
    // >();
    
    //auto& bus = GET_DIGITAL_BUS_REGS<DBB>();

    //bus.PORT |= 0b1;

    auto& tm = GET_TIMER_REGS<TM2>();
    tm.TCCRA |= 0b101;
/*

00000100 <main>:
 100:	80 91 b0 00 	lds	r24, 0x00B0	; 0x8000b0 <__TEXT_REGION_LENGTH__+0x7c00b0>
 104:	85 60       	ori	r24, 0x05	; 5
 106:	80 93 b0 00 	sts	0x00B0, r24	; 0x8000b0 <__TEXT_REGION_LENGTH__+0x7c00b0>

*/
    //TCCR2A |= 0b101;

    while(1)
    {
    }

    return 0;
}