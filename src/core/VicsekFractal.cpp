#include "core/VicsekFractal.h"
#include <GL/gl.h>

void VicsekFractal::draw(int step) {
    glColor3f(0.9f, 0.6f, 0.1f);
    drawVicsek(-0.5f, -0.5f, 1.0f, step);
}

void VicsekFractal::drawVicsek(float x, float y, float size, int depth) {
    if (depth == 0) {
        drawSquare(x, y, size);
        return;
    }

    float newSize = size / 3.0f;

    drawVicsek(x, y, newSize, depth - 1);  
    drawVicsek(x + 2 * newSize, y, newSize, depth - 1);                 
    drawVicsek(x + newSize, y + newSize, newSize, depth - 1);          
    drawVicsek(x, y + 2 * newSize, newSize, depth - 1);               
    drawVicsek(x + 2 * newSize, y + 2 * newSize, newSize, depth - 1);  
}

void VicsekFractal::drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}
