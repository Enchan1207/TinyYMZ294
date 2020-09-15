/*
 * YMZ294 library  ver 0.5
 * 2020 @Enchan1207
*/
#include <YMZ294.h>

void YMZ294::noteOn(uint8_t ch, uint8_t num, uint8_t velocity) {
    uint16_t freq = (uint16_t *)pgm_read_word(&(freqs[num]));
    setFrequency(ch, freq);
    setVolume(ch, volume[ch]);
    setMixer(ch, 1);
}

void YMZ294::noteOff(uint8_t ch, uint8_t velocity) {
    setVolume(ch, 0);
    setMixer(ch, 0);
}

void YMZ294::controlChange(uint8_t ch, uint8_t control, uint8_t param) {
    switch (control & 0x1F) {
        case CTRL_VOLUME:
            setVolume(ch, param >> 3);
            break;
        
        default:
            break;
    }
}

void YMZ294::programChange(uint8_t num) {
    setEnvShape(num);
}
