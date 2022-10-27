#ifndef DC_MOTOR
#define DC_MOTOR

#include <entities.h>
#include <Arduino.h>

class dcMotor: public Actuator {
    private:
        uint8_t pin;
        String units;
    public:
        dcMotor(uint8_t id, String reference, uint8_t pin): Actuator(id, reference){
            this->pin=pin;
        };
        void begin();
        void setOutput(int output, String units);
        int getOutput();  
        String getUnits();
        uint8_t getPin();
};
void dcMotor::begin(){
    pinMode(this->pin,OUTPUT);
};
void dcMotor::setOutput(int out, String units){
    this->units=units;
    this->output=out;
    analogWrite(this->pin,this->output);
};
int dcMotor::getOutput(){
    return this->output;
}
String dcMotor::getUnits(){
    return this->units;
}
uint8_t dcMotor::getPin(){
    return this->pin;
};
#endif