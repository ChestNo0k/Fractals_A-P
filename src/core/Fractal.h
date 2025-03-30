#pragma once

class Fractal {
public:
    virtual void draw(int step) = 0;
    virtual ~Fractal() = default;
};
