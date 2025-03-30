#pragma once

#include "core/Fractal.h"

class KochFractal : public Fractal {
public:
    void draw(int step) override;

private:
    void koch(float size, int depth);
    void turn(float angle);
    void move(float distance);
    void resetTurtle();

    float x, y;
    float heading;
};
