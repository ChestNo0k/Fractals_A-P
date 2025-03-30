#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <memory>
#include "core/Fractal.h"

class FractalGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    explicit FractalGLWidget(QWidget *parent = nullptr);
    void setFractal(std::unique_ptr<Fractal> fractal);
    void setStep(int step);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    std::unique_ptr<Fractal> currentFractal;
    int currentStep;
};
