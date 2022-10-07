#ifndef OLED_I2C
#define OLED_I2C

#include <entities.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Oled_128x64: public HMI, public Adafruit_SSD1306 {
    private:
        uint8_t width;
        uint8_t height;
        TwoWire twi;
        int8_t rst_pin;
        uint8_t oled_Addr;
    public:
        Oled_128x64(uint8_t id, String reference, uint8_t oled_Addr, uint8_t width, uint8_t height, TwoWire *twi, 
        uint8_t rstPin): HMI(id, reference), Adafruit_SSD1306(width, height, twi, rstPin){
                this->oled_Addr = oled_Addr;
        };
        void start();
        void showVariable(String reference, int output, String units);   
        void showVibrationsAlert();
};
void Oled_128x64::start(){
    this->begin(SSD1306_SWITCHCAPVCC, this->oled_Addr);
    this->clearDisplay();
}
void Oled_128x64::showVariable(String reference, int output, String units){
    this->clearDisplay();
    this->setTextSize(2);
    this->setTextColor(SSD1306_WHITE);
    this->setCursor(0,0);
    this->print(reference);
    this->print(": ");
    this->setTextSize(3);
    this->setCursor(20,28);
    this->print(output);
    this->setTextSize(2);
    this->setCursor(90,30);
    this->print(units);
    this->display();
};
void Oled_128x64::showVibrationsAlert(){
    this->clearDisplay();
    this->setTextSize(2);
    this->setTextColor(SSD1306_WHITE);
    this->setCursor(5,0);
    this->print("ALERT!!");
    this->setTextSize(2);
    this->setCursor(5,17);
    this->print("CHECK");
    this->setTextSize(2);
    this->setCursor(5,34);
    this->print("VIBRATIONS");
    this->display();
}

#endif