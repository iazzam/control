#include <MemoryFree.h>
#include "SRAM.h"

SRAM::SRAM(const String name, const uint8_t freq) : Sensor{name, freq, 1} {}

float SRAM::read() {
    add(freeMemory());
    return get(0);
}
