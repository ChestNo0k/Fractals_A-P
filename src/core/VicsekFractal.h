#pragma once

#include "core/Fractal.h"

class VicsekFractal : public Fractal {
public:
    void draw(int step) override;

private:
    void drawVicsek(float x, float y, float size, int depth);
    void drawSquare(float x, float y, float size);
};
