#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onVisualizeClicked();
    void onExitClicked();

private:
    QPushButton *visualizeButton;
    QPushButton *exitButton;
    QComboBox *fractalComboBox;
};
