#include "avr/interrupt.h"
#include "pitches.h" 

volatile bool btn_c;
volatile bool btn_d;
volatile bool btn_e;
volatile bool btn_f;
volatile bool btn_g;
volatile bool btn_a;
volatile bool btn_b;
volatile bool btn_c2;

int pin_c = 2;
int pin_d = 3;
int pin_e = 4;
int pin_f = 5;
int pin_g = 6;
int pin_a = 7;
int pin_b = 8;
int pin_c2 = 9;

int pin_buzzer = 12;

void setup() {  
  pinMode(pin_c, INPUT_PULLUP);
  pinMode(pin_d, INPUT_PULLUP);
  pinMode(pin_e, INPUT_PULLUP);
  pinMode(pin_f, INPUT_PULLUP);
  pinMode(pin_g, INPUT_PULLUP);
  pinMode(pin_a, INPUT_PULLUP);
  pinMode(pin_b, INPUT_PULLUP);
  pinMode(pin_c2, INPUT_PULLUP);
  
  PCICR |= B00000101; // Enable interrupts on PD and PB ports
  
  PCMSK0 |= B00000011; //D8, D9 (PB port)
  PCMSK2 |= B11111100; // Trigger interrupts on pins D2-D7

}

void loop() {
  
}

ISR (PCINT0_vect) {
  //Note B  
  btn_b = digitalRead(pin_b);
  if(btn_b == LOW){
    tone(pin_buzzer, NOTE_B4);
    return; 
  }
  if(btn_b == HIGH){
    noTone(pin_buzzer);
  }

  //Note C2  
  btn_c2 = digitalRead(pin_c2);
  if(btn_c2 == LOW){
    tone(pin_buzzer, NOTE_C5);
    return; 
  }
  if(btn_c2 == HIGH){
    noTone(pin_buzzer);
  }
}

ISR (PCINT2_vect) {
  //Note C  
  btn_c = digitalRead(pin_c);
  if(btn_c == LOW){
    tone(pin_buzzer, NOTE_C4);
    return; 
  }
  if(btn_c == HIGH){
    noTone(pin_buzzer);
  }

  //Note D
  btn_d = digitalRead(pin_d);
  if(btn_d == LOW){
    tone(pin_buzzer, NOTE_D4);
    return; 
  }
  if(btn_d == HIGH){
    noTone(pin_buzzer);
  }


  //Note E
  btn_e = digitalRead(pin_e);
  if(btn_e == LOW){
    tone(pin_buzzer, NOTE_E4);
    return; 
  }
  if(btn_e == HIGH){
    noTone(pin_buzzer);
  }

  //Note F
  btn_f = digitalRead(pin_f);
  if(btn_f == LOW){
    tone(pin_buzzer, NOTE_F4); 
    return;
  }
  if(btn_f == HIGH){
    noTone(pin_buzzer);
  }

  //Note G  
  btn_g = digitalRead(pin_g);
  if(btn_g == LOW){
    tone(pin_buzzer, NOTE_G4);
    return; 
  }
  if(btn_g == HIGH){
    noTone(pin_buzzer);
  }

  //Note A  
  btn_a = digitalRead(pin_a);
  if(btn_a == LOW){
    tone(pin_buzzer, NOTE_A4);
    return; 
  }
  if(btn_a == HIGH){
    noTone(pin_buzzer);
  }

}
