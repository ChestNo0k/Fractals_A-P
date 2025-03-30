#pragma once

#include "core/Fractal.h"

class TreeFractal : public Fractal {
public:
    void draw(int step) override;

private:
    void drawBranch(float x1, float y1, float angle, float length, int depth, int maxDepth);
};
