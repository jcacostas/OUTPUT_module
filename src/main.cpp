#include <Arduino.h>
#include <DC_MOTOR.h>
#include <OLED_I2C.h>

dcMotor fan = dcMotor(0X01, "AXIAL FAN", 5);
dcMotor pump = dcMotor(0X02, "PUMP R134", 6);
Oled_128x64 oled_screen= Oled_128x64(0X03, "Screen", 0x3C, 128, 64, &Wire, -1);

int element=1;
unsigned long temp=millis();

void setup()
{
    Serial.begin(9600);
    fan.begin();
    pump.begin();
    oled_screen.start();
    oled_screen.showVibrationsAlert();
    delay(2000);
}

void loop()
{  
    if ((millis()-temp>2500)&&(element==0X01)){
        oled_screen.showVariable(fan.getReference(), fan.getOutput(), fan.getUnits());
        element=0X02;
        temp=millis();
    };
    if ((millis()-temp>2500)&&(element==0X02)){
        oled_screen.showVariable(pump.getReference(), pump.getOutput(), pump.getUnits());
        element=0X01;
        temp=millis();
    };
    fan.setOutput(200,"Hz");
    pump.setOutput(100,"Hz");
}
