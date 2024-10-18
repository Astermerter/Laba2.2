#include "head.h"
#include <iostream>
#include <assert.h>
using namespace std;

Lamp::Lamp() {
    force = 0;
    power = 0;
    intensivity = 0;
}

Lamp::Lamp(float init_force, float init_power, float init_intensivity) {
    if (init_force >= 0)
        force = init_force;
    else
        force = 0;
    if (init_power >= 0)
        power = init_power;
    else
        power = 0;
    if (init_intensivity >= 0)
        intensivity = init_intensivity;
    else
        intensivity = 0;
}

Lamp::Lamp(Lamp& another) {
    force = another.force;
    power = another.power;
    intensivity = another.intensivity;
}

void Lamp::setForce(float input_force) {
    if (input_force >= 0)
        force = input_force;
    else
        force = 0;
}

void Lamp::setPower(float input_power) {
    if (input_power >= 0)
        power = input_power;
    else
        power = 0;
}

void Lamp::setIntensivity(float input_intensivity) {
    if (input_intensivity >= 0)
        intensivity = input_intensivity;
    else
        intensivity = 0;
}

float Lamp::getForce() const {
    return force;
}

float Lamp::getPower() const {
    return power;
}

float Lamp::getintensivity() const {
    return intensivity;
}

// ==========================================================================================================

LedLamp::LedLamp()
    :red_lamp(),
    blue_lamp(),
    green_lamp(),
    result_lamp()
{

}

LedLamp::LedLamp(float red_force, float red_power, float red_intensivity,
    float green_force, float green_power, float green_intensivity,
    float blue_force, float blue_power, float blue_intensivity)
    : red_lamp(red_force, red_power, red_intensivity),
    blue_lamp(blue_force, blue_power, blue_intensivity),
    green_lamp(green_force, green_power, green_intensivity),
    result_lamp()
{
    setResultLamp();
}

LedLamp::LedLamp(LedLamp& another): red_lamp(another.red_lamp), green_lamp(another.green_lamp), blue_lamp(another.blue_lamp), result_lamp(another.result_lamp)
{

}

void LedLamp::setResultLamp()
{
    result_lamp.setForce(red_lamp.getForce() * red_lamp.getintensivity()
        + green_lamp.getForce() * green_lamp.getintensivity()
        + blue_lamp.getForce() * blue_lamp.getintensivity());

    result_lamp.setPower(red_lamp.getPower() * red_lamp.getintensivity()
        + green_lamp.getPower() * green_lamp.getintensivity()
        + blue_lamp.getPower() * blue_lamp.getintensivity());

    result_lamp.setIntensivity(1);
}

float LedLamp::getRedLampForce() { return red_lamp.getForce(); }
float LedLamp::getGreenLampForce() { return green_lamp.getForce(); }
float LedLamp::getBlueLampForce() { return blue_lamp.getForce(); }

float LedLamp::getRedLampPower() { return red_lamp.getPower(); }
float LedLamp::getGreenLampPower() { return green_lamp.getPower(); }
float LedLamp::getBlueLampPower() { return blue_lamp.getPower(); }

float LedLamp::getRedLampIntensivity() { return red_lamp.getintensivity(); }
float LedLamp::getGreenLampIntensivity() { return green_lamp.getintensivity(); }
float LedLamp::getBlueLampIntensivity() { return blue_lamp.getintensivity(); }
//========================================
//========================================
void LedLamp::setRedLampForce(float red_force) { red_force >= 0 ? red_lamp.setForce(red_force) : red_lamp.setForce(0); } // очень грустные вырожения, но мне бы было грустнее сели бы количество строк выросло в 4 раза =(
void LedLamp::setGreenLampForce(float green_force) { green_force >= 0 ? green_lamp.setForce(green_force) : green_lamp.setForce(0); } // их нужно чувствовать, они все +- одинаковы
void LedLamp::setBlueLampForce(float blue_force) { blue_force >= 0 ? blue_lamp.setForce(blue_force) : blue_lamp.setForce(0); } // если ставить значения ламп вручную, то обязательно в конце запустить функцию setResultLamp();

void LedLamp::setRedLampPower(float red_power) { red_power >= 0 ? red_lamp.setPower(red_power) : red_lamp.setPower(0); }
void LedLamp::setGreenLampPower(float green_power) { green_power >= 0 ? green_lamp.setPower(green_power) : green_lamp.setPower(0); }
void LedLamp::setBlueLampPower(float blue_power) { blue_power >= 0 ? blue_lamp.setPower(blue_power) : blue_lamp.setPower(0); }

void LedLamp::setRedLampIntensivity(float red_intensivity) { red_intensivity >= 0 or red_intensivity <= 1 ? red_lamp.setIntensivity(red_intensivity) : red_lamp.setIntensivity(0); }
void LedLamp::setGreenLampIntensivity(float green_intensivity) { green_intensivity >= 0 or green_intensivity <= 1 ? green_lamp.setIntensivity(green_intensivity) : green_lamp.setIntensivity(0); }
void LedLamp::setBlueLampIntensivity(float blue_intensivity) { blue_intensivity >= 0 or blue_intensivity <= 1 ? blue_lamp.setIntensivity(blue_intensivity) : blue_lamp.setIntensivity(0); }
//========================================
//========================================
float LedLamp::getResultLampForce() { return result_lamp.getForce(); }
float LedLamp::getResultLampPower() { return result_lamp.getPower(); }



#include <cassert>
#include <iostream>

void test()
{
    LedLamp lamp1;

    assert(lamp1.getRedLampForce() == 0); assert(lamp1.getRedLampPower() == 0); assert(lamp1.getRedLampIntensivity() == 0);
    assert(lamp1.getGreenLampForce() == 0); assert(lamp1.getGreenLampPower() == 0); assert(lamp1.getGreenLampIntensivity() == 0);
    assert(lamp1.getBlueLampForce() == 0); assert(lamp1.getBlueLampPower() == 0); assert(lamp1.getBlueLampIntensivity() == 0);
    assert(lamp1.getResultLampForce() == 0);assert(lamp1.getResultLampPower() == 0);


    LedLamp lamp2(1, 2, 1, 3, 5, 0.5, 4, 5, 0);

    assert(lamp2.getRedLampForce() == 1); assert(lamp2.getRedLampPower() == 2); assert(lamp2.getRedLampIntensivity() == 1);
    assert(lamp2.getGreenLampForce() == 3); assert(lamp2.getGreenLampPower() == 5); assert(lamp2.getGreenLampIntensivity() == 0.5);
    assert(lamp2.getBlueLampForce() == 4); assert(lamp2.getBlueLampPower() == 5); assert(lamp2.getBlueLampIntensivity() == 0);
    assert(lamp2.getResultLampForce() == 2.5); assert(lamp2.getResultLampPower() == 4.5);


    LedLamp lamp3(lamp2);

    assert(lamp3.getRedLampForce() == 1); assert(lamp3.getRedLampPower() == 2); assert(lamp3.getRedLampIntensivity() == 1);
    assert(lamp3.getGreenLampForce() == 3); assert(lamp3.getGreenLampPower() == 5); assert(lamp3.getGreenLampIntensivity() == 0.5);
    assert(lamp3.getBlueLampForce() == 4); assert(lamp3.getBlueLampPower() == 5); assert(lamp3.getBlueLampIntensivity() == 0);
    assert(lamp3.getResultLampForce() == 2.5); assert(lamp3.getResultLampPower() == 4.5);


    LedLamp l;

    l.setRedLampForce(1); assert(l.getRedLampForce() == 1); l.setGreenLampForce(5); assert(l.getGreenLampForce() == 5); l.setBlueLampForce(10);  assert(l.getBlueLampForce() == 10);
    l.setRedLampPower(4); assert(l.getRedLampPower() == 4); l.setGreenLampPower(2); assert(l.getGreenLampPower() == 2); l.setBlueLampPower(15); assert(l.getBlueLampPower() == 15);
    l.setRedLampIntensivity(1); assert(l.getRedLampIntensivity() == 1); l.setGreenLampIntensivity(0.5); assert(l.getGreenLampIntensivity() == 0.5); l.setBlueLampIntensivity(1); assert(l.getBlueLampIntensivity() == 1);
    l.setResultLamp();assert(l.getResultLampForce() == 13.5); assert(l.getResultLampPower() == 20);    

    std::cout << "All tests Passed =)" << std::endl;
}
