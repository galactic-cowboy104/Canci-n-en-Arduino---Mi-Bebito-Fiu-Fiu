//MI BEBITO FIU FIU - TITO SILVA. by Zoé Trejo
#include "pitches.h"

int melody[] = {

  NOTE_GS4, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_E5,
  NOTE_CS5, NOTE_B4, NOTE_DS5, NOTE_B4, NOTE_CS5,
  NOTE_AS4, NOTE_B4, NOTE_DS5, NOTE_AS4, NOTE_DS5, NOTE_GS4,
  NOTE_GS4, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5,
  NOTE_CS5, NOTE_B4, NOTE_DS5, NOTE_CS5, NOTE_DS5,
  NOTE_FS5, NOTE_GS5, NOTE_DS5, NOTE_CS5, NOTE_DS5,
  NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_GS5, NOTE_CS5,
  NOTE_CS5, NOTE_B4, NOTE_DS5, NOTE_B4, NOTE_CS5,
  NOTE_B4, NOTE_CS5, NOTE_DS5, NOTE_DS5, NOTE_DS5,
  NOTE_DS5, NOTE_CS5, NOTE_DS5, NOTE_GS4, NOTE_DS5, NOTE_CS5,
  NOTE_B4, NOTE_GS4, NOTE_B4, NOTE_DS5, NOTE_B4, NOTE_CS5,
  NOTE_B4, NOTE_DS5, NOTE_B4, NOTE_CS5, NOTE_B4, NOTE_GS4, 0
  
};

float notesDurations[] = {   
        
  8, 4, 4, 4, 8,
  3, 4, 4, 8, 2,
  8, 4, 4, 4, 8, 2,
  8, 8, 4, 3, 4,
  4, 4, 4, 2, 8,
  4, 4, 4, 8, 2,
  8, 4, 3, 4, 4,
  8, 8, 4, 8, 3,
  8, 8, 4, 8, 4,
  8, 8, 2, 4, 8, 2,
  4, 8, 8, 4, 8, 2,
  8, 4, 4, 8, 8, 3, 3
  
};

int button = 2;
int speaker = 3;

int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int led5 = 8;
int led6 = 9;
int led7 = 10;
int led8 = 11;

int leds[8] = { 
  
  led1, led2, led3, led4, led5, led6, led7, led8
  
};


void setup() {

  pinMode(speaker, OUTPUT);
  pinMode(button, INPUT);

  for(int i = 0; i < 8; i ++)
    pinMode(leds[i], OUTPUT);

}
  
void loop() {

  for(int i = 0; i < 8; i ++)
    digitalWrite(leds[i], HIGH);
  
  int buttonstage = digitalRead(button);
  
  if (buttonstage == HIGH){

    for(int i = 0; i < 2; i ++) {
    
      for(int thisNote = 0; thisNote < 65; thisNote ++) {
        
          float noteDuration = 1195 / notesDurations[thisNote];    
  
          ledShow(thisNote);
           
          tone(speaker, melody[thisNote], noteDuration);
          
          float pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(speaker);
  
      }

    }
 
  }

}

void ledShow(int indicator) {

  if(melody[indicator] == NOTE_GS4)
    digitalWrite(led1, HIGH);
  else
    digitalWrite(led1, LOW);

  if(melody[indicator] == NOTE_AS4)
    digitalWrite(led2, HIGH);
  else
    digitalWrite(led2, LOW);

  if(melody[indicator] == NOTE_B4)
    digitalWrite(led3, HIGH);
  else
    digitalWrite(led3, LOW);

  if(melody[indicator] == NOTE_CS5)
    digitalWrite(led4, HIGH);
  else
    digitalWrite(led4, LOW);

  if(melody[indicator] == NOTE_DS5)
    digitalWrite(led5, HIGH);
  else
    digitalWrite(led5, LOW);

  if(melody[indicator] == NOTE_E5)
    digitalWrite(led6, HIGH);
  else
    digitalWrite(led6, LOW);

  if(melody[indicator] == NOTE_FS5)
    digitalWrite(led7, HIGH);
  else
    digitalWrite(led7, LOW);

  if(melody[indicator] == NOTE_GS5)
    digitalWrite(led8, HIGH);
  else
    digitalWrite(led8, LOW);

}
