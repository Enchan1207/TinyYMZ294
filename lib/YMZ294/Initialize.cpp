/*
 * YMZ294 library  ver 0.5
 * 2020 @Enchan1207
*/
#include <YMZ294.h>

YMZ294::YMZ294() {
}

void YMZ294::begin(){
    // port configuration
    for(uint8_t i = 2; i <= 9; i++){
        pinMode(i, OUTPUT);
    }
    pinMode(WR, OUTPUT);
    pinMode(CS, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(RESET, OUTPUT);

    mixerStat = 0b00111111;

    reset();
}

void YMZ294::reset(){
    // software reset
    digitalWrite(RESET, 0);
    delayMicroseconds(50);
    digitalWrite(RESET, 1);

    // mixer settings 0x07
    // volume settings 0x08-0x0A
    for (int ch = 0; ch < 3; ch++){
        setMixer(ch, 0);
        setVolume(ch, 0);
    }

    //  envelope freq
    setEnvShape(0b1100);
    setEnvFreq(60);
}
