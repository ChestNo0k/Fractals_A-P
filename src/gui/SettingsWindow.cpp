#include "SettingsWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    resolutionComboBox = new QComboBox(this);
    resolutionComboBox->addItems({"800x600", "1280x720", "1366x768", "1920x1080", "2560x1440"});

    themeComboBox = new QComboBox(this);
    themeComboBox->addItems({"Light", "Dark"});

    languageComboBox = new QComboBox(this);
    languageComboBox->addItems({"English", "Русский"});

    applyButton = new QPushButton("Apply", this);
    exitButton = new QPushButton("Exit", this);

    int buttonWidth = 100;
    applyButton->setFixedWidth(buttonWidth);
    exitButton->setFixedWidth(buttonWidth);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(applyButton);
    buttonsLayout->addWidget(exitButton);
    buttonsLayout->addStretch();

    mainLayout->addWidget(resolutionComboBox);
    mainLayout->addWidget(themeComboBox);
    mainLayout->addWidget(languageComboBox);
    mainLayout->addLayout(buttonsLayout);

    setCentralWidget(central);
    setFixedSize(300, 220);

    connect(applyButton, &QPushButton::clicked, this, &SettingsWindow::applySettings);
    connect(exitButton, &QPushButton::clicked, this, &SettingsWindow::closeSettings);
}

void SettingsWindow::applySettings() {
    QString resText = resolutionComboBox->currentText();
    QString theme = themeComboBox->currentText();
    QString lang = languageComboBox->currentText();

    QJsonObject obj;
    obj["Theme"] = theme;
    obj["WindowSize"] = resText;
    obj["Language"] = lang;

    QJsonDocument doc(obj);
    QFile file("settings.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson());
        file.close();
    }

    QMessageBox::information(this, "Settings", "Settings saved.\nPlease restart the application.");
}

void SettingsWindow::closeSettings() {
    close();
}
