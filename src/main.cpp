#include <Arduino.h>
#include <llp.h>
#include <DC_MOTOR.h>
#include <OLED_I2C.h>

DataPack input = DataPack();
dcMotor fan = dcMotor(0X01, "AXIAL FAN", 2);
dcMotor pump = dcMotor(0X02, "PUMP R134", 3);
Oled_128x64 oled_screen= Oled_128x64(0X03, "Screen", 0x3C, 128, 64, &Wire, -1);

int element=0x01;
unsigned long temp=millis();

void setup()
{
    Serial.begin(115200);
    fan.begin();
    pump.begin();
    oled_screen.start();
    fan.setOutput(200,"Hz");
    pump.setOutput(200,"Hz");
    oled_screen.showVariable(fan.getReference(), fan.getOutput(), fan.getUnits());
}

void loop()
{  
    if ((millis()-temp>2000)&&(element==0X01)){
        oled_screen.showVariable(fan.getReference(), fan.getOutput(), fan.getUnits());
        element=0X02;
        temp=millis();
    };
    if ((millis()-temp>2000)&&(element==0X02)){
        oled_screen.showVariable(pump.getReference(), pump.getOutput(), pump.getUnits());
        element=0X01;
        temp=millis();
    };
    /*if(input.available(Serial)){
        uint8_t counter = input.inWaiting();
        uint8_t* data_keys = input.getKeys();
        for(int i=0;i<counter;i++){
            uint8_t key = data_keys[i];
            uint16_t data = input.getData(data_keys[i]);
            uint8_t valor = map(data, 0, 100, 80, 255);
            if (key==0xc3){
                analogWrite(2,255);
                fan.setOutput(valor,"Hz");
            }
            if (key==0xc4){
                pump.setOutput(valor,"Hz");
            }
            if (key==0xc5){
                if (valor==255){
                    oled_screen.showVibrationsAlert();
                }
            }
        }
    }*/
}
