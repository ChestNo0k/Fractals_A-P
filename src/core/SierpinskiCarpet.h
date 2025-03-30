#pragma once

#include "core/Fractal.h"

class SierpinskiCarpet : public Fractal {
public:
    void draw(int step) override;

private:
    void drawCarpet(float x, float y, float size, int depth);
    void drawFilledSquare(float x, float y, float size);
};
