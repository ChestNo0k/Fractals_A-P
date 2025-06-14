#include "core/LevyFractal.h"
#include <GL/gl.h>
#include <cmath>

void LevyFractal::draw(int step) {
    float len = 1.2f;
    float x1 = -len / 2.0f;
    float y1 = 0.5f;
    float x2 = len / 2.0f;
    float y2 = 0.5f;

    glColor3f(0.6f, 0.2f, 0.8f);
    glLineWidth(1.5f);
    drawLevy(x1, y1, x2, y2, step);
}

void LevyFractal::drawLevy(float x1, float y1, float x2, float y2, int depth) {
    if (depth == 0) {
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    } else {
        float midX = (x1 + x2) / 2.0f + (y2 - y1) / 2.0f;
        float midY = (y1 + y2) / 2.0f - (x2 - x1) / 2.0f;

        drawLevy(x1, y1, midX, midY, depth - 1);
        drawLevy(midX, midY, x2, y2, depth - 1);
    }
}
