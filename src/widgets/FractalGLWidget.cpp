#include "widgets/FractalGLWidget.h"

FractalGLWidget::FractalGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), currentStep(0) {}

void FractalGLWidget::setFractal(std::unique_ptr<Fractal> fractal) {
    currentFractal = std::move(fractal);
    update();
}

void FractalGLWidget::setStep(int step) {
    currentStep = step;
    update();
}

void FractalGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void FractalGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = static_cast<float>(w) / static_cast<float>(h);
    if (aspect >= 1.0f) {
        glOrtho(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);
    } else {
        glOrtho(-1.0, 1.0, -1.0f / aspect, 1.0f / aspect, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
}


void FractalGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (currentFractal) {
        currentFractal->draw(currentStep);
    }
}
