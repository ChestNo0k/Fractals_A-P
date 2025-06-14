#pragma once

#include "core/Fractal.h"

class LevyFractal : public Fractal {
public:
    void draw(int step) override;

private:
    void drawLevy(float x1, float y1, float x2, float y2, int depth);
};
