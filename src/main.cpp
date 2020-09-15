/*
 * MidiUSB + YMZ294
*/
#include <Arduino.h>
#include <MIDIUSB.h>
#include <YMZ294.h>

YMZ294 ymz;

void setup() {
    // YMZ初期化
    ymz.begin();

}

void loop() {
    midiEventPacket_t event;
    event = MidiUSB.read();
    if(event.header != 0){
        digitalWrite(10,1);

        uint8_t command = event.byte1 & 0xF0;
        uint8_t channel = event.byte1 & 0x0F;

        switch (command) {
            case NOTE_ON:
                ymz.noteOn(channel, event.byte2, event.byte3);
                break;

            case NOTE_OFF:
                ymz.noteOff(channel, event.byte3);
                break;

            case PROGCHG:
                ymz.programChange(event.byte1);
                break;

            case CTRLCHG:
                switch (event.byte1) {
                    case CTRL_VOLUME:
                        ymz.setVolume(channel, event.byte2);
                        break;
                    
                    default:
                        break;
                }
                break;
            
            default:
                break;
        }
    }
}