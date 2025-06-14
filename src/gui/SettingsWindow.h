#pragma once

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>

class SettingsWindow : public QMainWindow {
    Q_OBJECT

public:
    SettingsWindow(QWidget *parent = nullptr);

private slots:
    void applySettings();
    void closeSettings();

private:
    QComboBox *resolutionComboBox;
    QComboBox *themeComboBox;
    QComboBox *languageComboBox;
    QPushButton *applyButton;
    QPushButton *exitButton;
};
