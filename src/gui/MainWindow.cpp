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

    fractalComboBox = new QComboBox(this);
    visualizeButton = new QPushButton(this);
    settingsButton = new QPushButton(this);
    exitButton = new QPushButton(this);

    int width = 200;
    visualizeButton->setFixedWidth(width);
    settingsButton->setFixedWidth(width);
    exitButton->setFixedWidth(width);
    fractalComboBox->setFixedWidth(width);

    QHBoxLayout *comboLayout = new QHBoxLayout();
    comboLayout->addStretch();
    comboLayout->addWidget(fractalComboBox);
    comboLayout->addStretch();

    QHBoxLayout *visLayout = new QHBoxLayout();
    visLayout->addStretch();
    visLayout->addWidget(visualizeButton);
    visLayout->addStretch();

    QHBoxLayout *setLayout = new QHBoxLayout();
    setLayout->addStretch();
    setLayout->addWidget(settingsButton);
    setLayout->addStretch();

    QHBoxLayout *exitLayout = new QHBoxLayout();
    exitLayout->addStretch();
    exitLayout->addWidget(exitButton);
    exitLayout->addStretch();

    layout->addLayout(comboLayout);
    layout->addLayout(visLayout);
    layout->addLayout(setLayout);
    layout->addLayout(exitLayout);
    setCentralWidget(central);

    connect(visualizeButton, &QPushButton::clicked, this, &MainWindow::onVisualizeClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(settingsButton, &QPushButton::clicked, this, []() {
        auto s = new SettingsWindow();
        s->show();
    });

    loadAndApplySettings();
    applyLanguage();
}

void MainWindow::loadAndApplySettings() {
    QFile file("settings.json");

    if (!file.exists()) {
        QJsonObject def;
        def["Theme"] = "Dark";
        def["WindowSize"] = "800x600";
        def["Language"] = "English";
        QJsonDocument doc(def);
        QFile create("settings.json");
        if (create.open(QIODevice::WriteOnly | QIODevice::Text)) {
            create.write(doc.toJson());
            create.close();
        }
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();

    QString theme = obj["Theme"].toString("Light");
    QString sizeStr = obj["WindowSize"].toString("800x600");
    currentLanguage = obj["Language"].toString("English");

    QStringList parts = sizeStr.split("x");
    if (parts.size() == 2) {
        resize(parts[0].toInt(), parts[1].toInt());
    }

    if (theme == "Dark") {
        qApp->setStyleSheet("QWidget { background-color: #121212; color: white; }");
    } else {
        qApp->setStyleSheet("");
    }
}

void MainWindow::applyLanguage() {
    if (currentLanguage == "Русский") {
        visualizeButton->setText("Визуализировать");
        settingsButton->setText("Настройки");
        exitButton->setText("Выход");

        fractalComboBox->addItem("Фрактал Вичека");
        fractalComboBox->addItem("Дерево");
        fractalComboBox->addItem("Ковёр Серпинского");
        fractalComboBox->addItem("Снежинка Коха");
        fractalComboBox->addItem("Спиральный фрактал");
        fractalComboBox->addItem("H-фрактал");
        fractalComboBox->addItem("Кривая Леви");
        fractalComboBox->addItem("Кривая Хильберта");
    } else {
        visualizeButton->setText("Visualize");
        settingsButton->setText("Settings");
        exitButton->setText("Exit");

        fractalComboBox->addItem("Vicsek Fractal");
        fractalComboBox->addItem("Tree");
        fractalComboBox->addItem("Sierpinski Carpet");
        fractalComboBox->addItem("Koch Snowflake");
        fractalComboBox->addItem("Spiral Fractal");
        fractalComboBox->addItem("H-Fractal");
        fractalComboBox->addItem("Levy C Curve");
        fractalComboBox->addItem("Hilbert Curve");
    }
}

void MainWindow::onVisualizeClicked() {
    QString selected = fractalComboBox->currentText();
    auto visualizer = new VisualizerWindow(selected, size(), this);
    visualizer->show();
}
