#ifndef ENTITIES
#define ENTITIES

#include <stdint.h>
#include <Arduino.h>

class Device {
    private:
        uint8_t id;
        String reference;
    public:
        Device(uint8_t,String);
        uint8_t getId();
        String getReference();
};
Device::Device(uint8_t id, String reference){
    this->id = id;
    this->reference = reference;
};
uint8_t Device::getId(){
    return this->id;
};
String Device::getReference(){
    return this->reference;
};

class Actuator : public Device {
    protected:
        int output;
    public:
        Actuator(uint8_t id, String reference): Device(id, reference){
        };
        virtual void setOutput(int output, String units)=0;
};

class HMI : public Device {
    protected:
        int output;
    public:
        HMI(uint8_t id, String reference): Device(id, reference){};
        virtual void showVariable(String reference, int output, String units)=0;
        virtual void showVibrationsAlert()=0;
};

#endif