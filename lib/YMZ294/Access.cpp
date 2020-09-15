/*
 * YMZ294 library  ver 0.5
 * 2020 @Enchan1207
*/
#include <YMZ294.h>

// write to YMZ294 by specifying address
void YMZ294::writeAt(uint8_t addr, uint8_t data){
    write(ADDR, addr);
    write(DATA, data);
}

// write to YMZ294
void YMZ294::write(boolean isData, uint8_t data){
    // set data storing place
    digitalWrite(A0, isData);

    // output pin initialize
    for(uint8_t i = 2; i <= 9; i++){
        digitalWrite(i, 0);
    }

    // begin transaction
    digitalWrite(WR, 0);
    digitalWrite(CS, 0);

    // write via digital Pins
    for(uint8_t i = 2; i <= 9; i++){
        digitalWrite(i, bitRead(data, i - 2));
    }

    delayMicroseconds(30); // min CS pulse >= 30us

    // end transaction
    digitalWrite(WR, 1);
    digitalWrite(CS, 1);
}

