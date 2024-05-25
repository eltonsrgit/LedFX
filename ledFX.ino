#include <Adafruit_NeoPixel.h>

#define PIN 6 // pino do anel de leds
#define NUMPIXELS 8 // quantidade de leds do anel
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // necessário

void setup(){
  pixels.begin(); // inicializa o objeto pixels
  pixels.setBrightness(30); // brilho de 0 até 255
  pixels.clear(); // "limpa" tudo, apaga todos os leds
  ledLight(0, 0, 0);
}

void loop(){ // combine os valores r, g, b, para obter novas cores!
  ledPatrol(150, 0, 0, 0, 0, 150, 50);
  //ledBlink(0, 150, 0, 700);
  //ledLight(0, 150, 0);
  //ledCircle(0, 0, 150, 500);
  //ledCircleBlink(150, 0, 150, 700);
}


void ledBlink(uint8_t r, uint8_t g, uint8_t b, int time) { // pisca todas os leds em um intervalo de tempo
  pixels.clear();
  for(uint8_t i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();   
  }
  pixels.clear();
  delay(time);
  for(uint8_t i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();    
  }
  delay(time);
}

/*----------------------------------------------------------------------------------------*/
void ledLight (uint8_t r, uint8_t g, uint8_t b) { // luz contínua
  pixels.clear();
  for(uint8_t i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();    
  }
}

/*----------------------------------------------------------------------------------------*/
void ledCircle(uint8_t r, uint8_t g, uint8_t b, int time) { // luzes "andam" em círculo numa certa velocidade dependendo do tempo
  pixels.clear();
  for(uint8_t i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();    
    delay(time);
    pixels.clear(); 
  }
}

/*----------------------------------------------------------------------------------------*/
void ledCircleBlink(uint8_t r, uint8_t g, uint8_t b, int time) { // luzes "andam" em círculo e piscam no final numa certa velocidade dependendo do tempo
  pixels.clear();
  for(uint8_t i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();    
  }
  for(uint8_t i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();
    delay(time);
    pixels.clear();
  }
}


void ledPatrol(uint8_t r, uint8_t g, uint8_t b, uint8_t r2, uint8_t g2, uint8_t b2, int time) { // luzes "andam" em círculo e piscam no final numa certa velocidade dependendo do tempo
  pixels.clear();
  for(int i = 0; i < NUMPIXELS; i++) { 
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();
    delay(time);
  }
  for(int i = NUMPIXELS; i > 0; i--) { 
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(r2, g2, b2));
    pixels.show();
    delay(time);
  }
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i+1, pixels.Color(150, 150, 150));
    pixels.show();
  }
  delay(time);
}
