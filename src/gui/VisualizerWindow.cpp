#include "VisualizerWindow.h"
#include "core/TreeFractal.h"
#include "core/SierpinskiCarpet.h"
#include "core/KochFractal.h"
#include "core/SpiralFractal.h"
#include "core/VicsekFractal.h"

VisualizerWindow::VisualizerWindow(const QString &fractalType, QWidget *parent)
: QMainWindow(parent), step(0), currentFractalType(fractalType) {
QWidget *central = new QWidget(this);
QVBoxLayout *mainLayout = new QVBoxLayout(central);

glWidget = new FractalGLWidget(this);
if (fractalType == "Tree") {
    glWidget->setFractal(std::make_unique<TreeFractal>());
} else if (fractalType == "Koch Snowflake") {
    glWidget->setFractal(std::make_unique<KochFractal>());
} else if (fractalType == "Sierpinski Carpet") {
    glWidget->setFractal(std::make_unique<SierpinskiCarpet>());
} else if (fractalType == "Spiral Fractal") {
    glWidget->setFractal(std::make_unique<SpiralFractal>());
} else if (fractalType == "Vicsek Fractal") {
    glWidget->setFractal(std::make_unique<VicsekFractal>());
}
    

infoLabel = new QLabel(this);
infoLabel->setText("Fractal: " + currentFractalType + " | Step: " + QString::number(step));

nextStepButton = new QPushButton("Next step", this);
exitButton = new QPushButton("Exit", this);

QHBoxLayout *bottomLayout = new QHBoxLayout();
bottomLayout->addWidget(exitButton);
bottomLayout->addWidget(nextStepButton);
bottomLayout->addStretch();
bottomLayout->addWidget(infoLabel);

mainLayout->addWidget(glWidget, 1);
mainLayout->addLayout(bottomLayout);

setCentralWidget(central);
resize(640, 400);

connect(nextStepButton, &QPushButton::clicked, this, &VisualizerWindow::onNextStepClicked);
connect(exitButton, &QPushButton::clicked, this, &VisualizerWindow::onExitClicked);
}



void VisualizerWindow::onNextStepClicked() {
    step++;
    glWidget->setStep(step);
    infoLabel->setText("Fractal: " + currentFractalType + " | Step: " + QString::number(step));
}


void VisualizerWindow::onExitClicked() {
    close();
}
