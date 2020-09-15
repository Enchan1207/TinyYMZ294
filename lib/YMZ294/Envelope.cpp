/*
 * YMZ294 library  ver 0.5
 * 2020 @Enchan1207
*/
#include <YMZ294.h>

void YMZ294::setEnvShape(uint8_t shape) {
    writeAt(0x0D, shape & 0x0F);
}

void YMZ294::setEnvFreq(uint16_t freq) {
    uint16_t intFreq = (uint16_t)(2E6 / (256 * freq));
    writeAt(0x0B, intFreq & 0xFF);
    writeAt(0x0C, (intFreq & 0xFF00) >> 8);
}
