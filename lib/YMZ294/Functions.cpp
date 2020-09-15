/*
 * YMZ294 library  ver 0.5
 * 2020 @Enchan1207
*/
#include <YMZ294.h>

// set freqency
void YMZ294::setFrequency(uint8_t ch, uint16_t freq){
    if(ch > 2){
        return;
    }
    writeAt(ch * 2 + 0x00, freq & 0xff);
    writeAt(ch * 2 + 0x01, (freq & 0xff00) >> 8);
}

// set volume (volume: 0x00~0x0f)
void YMZ294::setVolume(uint8_t ch, uint8_t volume){
    if(ch > 2){
        return;
    }
    writeAt(ch + 0x08, volume & 0x0f);
}

// set mixer status
void YMZ294::setMixer(uint8_t ch, boolean isOutput){
    if(ch > 2){
        return;
    }
    bitWrite(mixerStat, ch, !isOutput);
    writeAt(0x07, mixerStat);
}
