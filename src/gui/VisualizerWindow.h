#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include "widgets/FractalGLWidget.h"

class VisualizerWindow : public QMainWindow {
    Q_OBJECT

public:
    VisualizerWindow(const QString &fractalType, QWidget *parent = nullptr);

private slots:
    void onNextStepClicked();
    void onExitClicked();

private:
    FractalGLWidget *glWidget;
    QLabel *infoLabel;
    QPushButton *nextStepButton;
    QPushButton *exitButton;
    int step;
    QString currentFractalType;
};
