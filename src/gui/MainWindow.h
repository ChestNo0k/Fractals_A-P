#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QSize>
#include <QString>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onVisualizeClicked();

private:
    void loadAndApplySettings();

    QPushButton *visualizeButton;
    QPushButton *settingsButton;
    QPushButton *exitButton;
    QComboBox *fractalComboBox;
};
