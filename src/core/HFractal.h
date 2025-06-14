#pragma once

#include "core/Fractal.h"

class HFractal : public Fractal {
public:
    void draw(int step) override;

private:
    void drawH(float x, float y, float size, int depth);
};
