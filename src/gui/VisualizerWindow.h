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
    VisualizerWindow(const QString &fractalType, QSize initialSize, QWidget *parent = nullptr);

private slots:
    void onNextStepClicked();
    void onExitClicked();
    void onHelpClicked();

private:
    QString getFractalInfo(const QString &type);
    QString mapFractalNameToId(const QString &name);

    FractalGLWidget *glWidget;
    QLabel *infoLabel;
    QPushButton *nextStepButton;
    QPushButton *exitButton;
    QPushButton *helpButton;
    int step;
    QString currentFractalType;
};
