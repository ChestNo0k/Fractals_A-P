#include "MainWindow.h"
#include "VisualizerWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    fractalComboBox = new QComboBox(this);
    fractalComboBox->addItem("Tree");
    fractalComboBox->addItem("Koch Snowflake");

    visualizeButton = new QPushButton("Visualize", this);
    exitButton = new QPushButton("Exit", this);

    layout->addWidget(fractalComboBox);
    layout->addWidget(visualizeButton);
    layout->addWidget(exitButton);

    setCentralWidget(central);
    setFixedSize(640, 400);

    connect(visualizeButton, &QPushButton::clicked, this, &MainWindow::onVisualizeClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);
}

void MainWindow::onVisualizeClicked() {
    auto visualizer = new VisualizerWindow(fractalComboBox->currentText(), this);
    visualizer->show();
}

void MainWindow::onExitClicked() {
    close();
}
