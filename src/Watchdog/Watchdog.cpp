#include "Watchdog.h"

void Watchdog::setup() {
    wdt_disable();

    cli();          // disable all interrupts
    wdt_reset();    // reset the WDT timer

    /*
    WDTCSR configuration:
    WDIE = 1: Interrupt Enable
    WDE = 1 :Reset Enable
    WDP3 = 0 :For 250ms Time-out
    WDP2 = 1 :For 250ms Time-out
    WDP1 = 1 :For 250ms Time-out
    WDP0 = 0 :For 250ms Time-out
    */

    // Enter Watchdog Configuration mode:
    WDTCSR |= (1<<WDCE) | (1<<WDE);

    // Set Watchdog settings:
    WDTCSR = (1<<WDIE) | (1<<WDE) | (0<<WDP3) | (1<<WDP2) | (1<<WDP1) | (0<<WDP0);

    sei();
}

void Watchdog::reset() {
    wdt_reset();
}

State Watchdog::get() {
    State readState;
    EEPROM.get(0, readState);

    State returnState;

    if (readState.reset)
        returnState = readState;

    for (int i = 0; i <= sizeof(readState); ++i)
        EEPROM.write(i, 0);

    return returnState;
}

void Watchdog::add(State &s) {
    s.reset = true;
    EEPROM.put(0, s);
}

void Watchdog::restartBoard(State &s) {
    add(s);
    restartBoard();
}

void Watchdog::restartBoard() {
    asm volatile ("  jmp 0");
}
