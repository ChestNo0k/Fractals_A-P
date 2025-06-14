#include "core/SpiralFractal.h"
#include <GL/gl.h>
#include <cmath>

void SpiralFractal::draw(int step) {
  glColor3f(1.0f, 0.2f, 0.8f);
  resetTurtle();

  int segments = 1 + step * 30;
  float length = 0.2f;
  float angle = 12.0f;
  drawSpiral(segments, length, angle);
}

void SpiralFractal::drawSpiral(int depth, float length, float angleDelta) {
  float shrink = 0.99f;
  for (int i = 0; i < depth; ++i) {
    move(length);
    turn(angleDelta);
    length *= shrink;
  }
}

void SpiralFractal::move(float distance) {
  float rad = heading * M_PI / 180.0f;
  float newX = x + cos(rad) * distance;
  float newY = y + sin(rad) * distance;

  glBegin(GL_LINES);
  glVertex2f(x, y);
  glVertex2f(newX, newY);
  glEnd();

  x = newX;
  y = newY;
}

void SpiralFractal::turn(float angle) { heading += angle; }

void SpiralFractal::resetTurtle() {
  x = 0.0f;
  y = -0.95f;
  heading = 0.0f;
}
