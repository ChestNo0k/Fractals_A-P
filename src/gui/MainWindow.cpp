#include "MainWindow.h"
#include "VisualizerWindow.h"
#include "SettingsWindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    int elementWidth = 200;

    fractalComboBox = new QComboBox(this);
    fractalComboBox->addItem("Hilbert Curve");
    fractalComboBox->addItem("Levy C Curve");
    fractalComboBox->addItem("H-Fractal");
    fractalComboBox->addItem("Vicsek Fractal");
    fractalComboBox->addItem("Tree");
    fractalComboBox->addItem("Sierpinski Carpet");
    fractalComboBox->addItem("Koch Snowflake");
    fractalComboBox->addItem("Spiral Fractal");
    fractalComboBox->setFixedWidth(elementWidth);

    visualizeButton = new QPushButton("Visualize", this);
    settingsButton = new QPushButton("Settings", this);
    exitButton = new QPushButton("Exit", this);

    visualizeButton->setFixedWidth(elementWidth);
    settingsButton->setFixedWidth(elementWidth);
    exitButton->setFixedWidth(elementWidth);

    QHBoxLayout *comboLayout = new QHBoxLayout();
    comboLayout->addStretch();
    comboLayout->addWidget(fractalComboBox);
    comboLayout->addStretch();

    QHBoxLayout *visualizeLayout = new QHBoxLayout();
    visualizeLayout->addStretch();
    visualizeLayout->addWidget(visualizeButton);
    visualizeLayout->addStretch();

    QHBoxLayout *settingsLayout = new QHBoxLayout();
    settingsLayout->addStretch();
    settingsLayout->addWidget(settingsButton);
    settingsLayout->addStretch();

    QHBoxLayout *exitLayout = new QHBoxLayout();
    exitLayout->addStretch();
    exitLayout->addWidget(exitButton);
    exitLayout->addStretch();

    layout->addLayout(comboLayout);
    layout->addLayout(visualizeLayout);
    layout->addLayout(settingsLayout);
    layout->addLayout(exitLayout);

    setCentralWidget(central);

    connect(visualizeButton, &QPushButton::clicked, this, &MainWindow::onVisualizeClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(settingsButton, &QPushButton::clicked, this, []() {
        auto s = new SettingsWindow();
        s->show();
    });

    loadAndApplySettings();
}

void MainWindow::loadAndApplySettings() {
    QFile file("settings.json");

    if (!file.exists()) {
        QJsonObject defaultSettings;
        defaultSettings["Theme"] = "Dark";
        defaultSettings["WindowSize"] = "800x600";

        QJsonDocument doc(defaultSettings);
        QFile createFile("settings.json");
        if (createFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            createFile.write(doc.toJson());
            createFile.close();
        }
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();

    QString theme = obj["Theme"].toString("Light");
    QString sizeStr = obj["WindowSize"].toString("800x600");

    QStringList parts = sizeStr.split("x");
    if (parts.size() == 2) {
        int w = parts[0].toInt();
        int h = parts[1].toInt();
        resize(w, h);
    }

    if (theme == "Dark") {
        qApp->setStyleSheet("QWidget { background-color: #121212; color: white; }");
    } else {
        qApp->setStyleSheet("");
    }
}

void MainWindow::onVisualizeClicked() {
    auto visualizer = new VisualizerWindow(fractalComboBox->currentText(), size(), this);
    visualizer->show();
}
