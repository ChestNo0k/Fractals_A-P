#include "core/SierpinskiCarpet.h"
#include <GL/gl.h>

void SierpinskiCarpet::draw(int step) {
  glColor3f(1.0f, 0.5f, 0.0f);
  drawCarpet(-0.8f, -0.8f, 1.6f, step);
}

void SierpinskiCarpet::drawCarpet(float x, float y, float size, int depth) {
  if (depth == 0) {
    drawFilledSquare(x, y, size);
    return;
  }

  float newSize = size / 3.0f;
  for (int dx = 0; dx < 3; ++dx) {
    for (int dy = 0; dy < 3; ++dy) {
      if (dx == 1 && dy == 1)
        continue;

      float newX = x + dx * newSize;
      float newY = y + dy * newSize;
      drawCarpet(newX, newY, newSize, depth - 1);
    }
  }
}

void SierpinskiCarpet::drawFilledSquare(float x, float y, float size) {
  glBegin(GL_QUADS);
  glVertex2f(x, y);
  glVertex2f(x + size, y);
  glVertex2f(x + size, y + size);
  glVertex2f(x, y + size);
  glEnd();
}
