#include "core/TreeFractal.h"
#include <cmath>
#include <GL/gl.h>

void TreeFractal::draw(int step) {
    glColor3f(0.0f, 1.0f, 0.0f);
    drawBranch(0.0f, -0.8f, 90.0f, 0.4f, 0, step);
}

void TreeFractal::drawBranch(float x1, float y1, float angle, float length, int depth, int maxDepth) {
    if (depth > maxDepth)
        return;

    float rad = angle * M_PI / 180.0f;
    float x2 = x1 + cos(rad) * length;
    float y2 = y1 + sin(rad) * length;

    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    drawBranch(x2, y2, angle - 30, length * 0.7f, depth + 1, maxDepth);
    drawBranch(x2, y2, angle + 30, length * 0.7f, depth + 1, maxDepth);
}
