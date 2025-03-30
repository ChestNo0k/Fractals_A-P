#pragma once

#include "core/Fractal.h"

class SpiralFractal : public Fractal {
public:
    void draw(int step) override;

private:
    void drawSpiral(int depth, float length, float angleDelta);
    void move(float distance);
    void turn(float angle);
    void resetTurtle();

    float x, y;
    float heading;
};
