#pragma once

#include "core/Fractal.h"

class HilbertFractal : public Fractal {
public:
    void draw(int step) override;

private:
    void hilbert(float x, float y, float xi, float xj, float yi, float yj, int n);
};
