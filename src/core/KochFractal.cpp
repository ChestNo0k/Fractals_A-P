#include "core/KochFractal.h"
#include <GL/gl.h>
#include <cmath>

void KochFractal::draw(int step) {
  glColor3f(0.0f, 0.6f, 1.0f);
  resetTurtle();

  for (int i = 0; i < 3; ++i) {
    koch(1.2f, step);
    turn(-120.0f);
  }
}

void KochFractal::koch(float size, int depth) {
  if (depth == 0) {
    move(size);
  } else {
    koch(size / 3.0f, depth - 1);
    turn(60.0f);
    koch(size / 3.0f, depth - 1);
    turn(-120.0f);
    koch(size / 3.0f, depth - 1);
    turn(60.0f);
    koch(size / 3.0f, depth - 1);
  }
}

void KochFractal::move(float distance) {
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

void KochFractal::turn(float angle) { heading += angle; }

void KochFractal::resetTurtle() {
  float size = 1.2f;
  float height = size * sqrt(3.0f) / 2.0f;

  x = -size / 2.0f;
  y = -height / 2.0f + 0.85;
  heading = 0.0f;
}
