#ifndef head
#define head

class Lamp {
public:
    Lamp();
    Lamp(float init_force, float init_power, float intensivity);
    Lamp(Lamp& another);

    void setForce(float input_force);
    void setPower(float input_power);
    void setIntensivity(float input_condition);

    float getForce() const;
    float getPower() const;
    float getintensivity() const;

private:
    float force;    // 0-inf
    float power;    // 0-inf
    float intensivity; // 0-1
};

class LedLamp
{
public:
    LedLamp();
    LedLamp(float red_force, float red_power, float red_intensivity,
        float green_force, float green_power, float green_intensivity,
        float blue_force, float blue_power, float blue_intensivity);
    LedLamp(LedLamp& another);

    void setResultLamp();


    float getRedLampForce();
    float getGreenLampForce();
    float getBlueLampForce();

    float getRedLampPower();
    float getGreenLampPower();
    float getBlueLampPower();

    float getRedLampIntensivity();
    float getGreenLampIntensivity();
    float getBlueLampIntensivity();


    void setRedLampForce(float red_force);
    void setGreenLampForce(float green_force);
    void setBlueLampForce(float blue_force);

    void setRedLampPower(float red_power);
    void setGreenLampPower(float green_power);
    void setBlueLampPower(float blue_power);

    void setRedLampIntensivity(float red_intensivity);
    void setGreenLampIntensivity(float green_intensivity);
    void setBlueLampIntensivity(float blue_intensivity);

    float getResultLampForce();
    float getResultLampPower();

private:
    Lamp red_lamp;
    Lamp blue_lamp;
    Lamp green_lamp;

    Lamp result_lamp;
};

void test();



#endif // !head
