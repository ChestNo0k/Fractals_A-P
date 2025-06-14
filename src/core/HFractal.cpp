#include "core/HFractal.h"
#include <GL/gl.h>

void HFractal::draw(int step) {
    drawH(0.0f, 0.0f, 1.0f, step);
}

void HFractal::drawH(float x, float y, float size, int depth) {
    float half = size / 2.0f;

    float x0 = x - half;
    float x1 = x + half;
    float y0 = y - half;
    float y1 = y + half;

    glColor3f(0.2f, 0.7f, 0.3f);

    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x0, y1);

    glVertex2f(x1, y0);
    glVertex2f(x1, y1);

    glVertex2f(x0, y);
    glVertex2f(x1, y);
    glEnd();

    if (depth > 0) {
        float newSize = size / 2.0f;
        drawH(x0, y1, newSize, depth - 1);
        drawH(x0, y0, newSize, depth - 1);
        drawH(x1, y1, newSize, depth - 1);
        drawH(x1, y0, newSize, depth - 1);
    }
}
