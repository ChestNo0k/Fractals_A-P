#include "core/HilbertFractal.h"
#include <GL/gl.h>

void HilbertFractal::draw(int step) {
    glColor3f(0.2f, 0.6f, 1.0f);
    glLineWidth(1.5f);

    float size = 1.6f;
    float x = -0.8f;
    float y = -0.8f;

    glBegin(GL_LINE_STRIP);
    hilbert(x, y, size, 0, 0, size, step);
    glEnd();
}

void HilbertFractal::hilbert(float x, float y, float xi, float xj, float yi, float yj, int n) {
    if (n <= 0) {
        float px = x + (xi + yi) / 2.0f;
        float py = y + (xj + yj) / 2.0f;
        glVertex2f(px, py);
    } else {
        hilbert(x, y,              yi/2,              yj/2,              xi/2,              xj/2, n - 1);
        hilbert(x + xi/2, y + xj/2, xi/2, xj/2,        yi/2, yj/2,        n - 1);
        hilbert(x + xi/2 + yi/2, y + xj/2 + yj/2, xi/2, xj/2, yi/2, yj/2, n - 1);
        hilbert(x + xi/2 + yi, y + xj/2 + yj, -yi/2, -yj/2, -xi/2, -xj/2, n - 1);
    }
}
