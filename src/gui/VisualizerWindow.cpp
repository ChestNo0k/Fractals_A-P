#include "VisualizerWindow.h"
#include "core/TreeFractal.h"
#include "core/SierpinskiCarpet.h"
#include "core/KochFractal.h"
#include "core/SpiralFractal.h"
#include "core/VicsekFractal.h"
#include "core/HFractal.h"
#include "core/LevyFractal.h"
#include "core/HilbertFractal.h"
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

VisualizerWindow::VisualizerWindow(const QString &fractalType, QSize initialSize, QWidget *parent)
    : QMainWindow(parent), step(0), currentFractalType(fractalType) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    glWidget = new FractalGLWidget(this);
    QString id = mapFractalNameToId(fractalType);
    if (id == "Tree") {
        glWidget->setFractal(std::make_unique<TreeFractal>());
    } else if (id == "Koch Snowflake") {
        glWidget->setFractal(std::make_unique<KochFractal>());
    } else if (id == "Sierpinski Carpet") {
        glWidget->setFractal(std::make_unique<SierpinskiCarpet>());
    } else if (id == "Spiral Fractal") {
        glWidget->setFractal(std::make_unique<SpiralFractal>());
    } else if (id == "Vicsek Fractal") {
        glWidget->setFractal(std::make_unique<VicsekFractal>());
    } else if (id == "H-Fractal") {
        glWidget->setFractal(std::make_unique<HFractal>());
    } else if (id == "Levy C Curve") {
        glWidget->setFractal(std::make_unique<LevyFractal>());
    } else if (id == "Hilbert Curve") {
        glWidget->setFractal(std::make_unique<HilbertFractal>());
    }

    infoLabel = new QLabel(this);
    infoLabel->setText("Fractal: " + currentFractalType + " | Step: " + QString::number(step));

    nextStepButton = new QPushButton("Next", this);
    exitButton = new QPushButton("Exit", this);
    helpButton = new QPushButton("?", this);
    helpButton->setFixedWidth(30);
    helpButton->setToolTip("Show fractal info");

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addStretch();
    topLayout->addWidget(helpButton);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(exitButton);
    bottomLayout->addWidget(nextStepButton);
    bottomLayout->addStretch();
    bottomLayout->addWidget(infoLabel);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(glWidget, 1);
    mainLayout->addLayout(bottomLayout);

    setCentralWidget(central);
    resize(initialSize);

    connect(nextStepButton, &QPushButton::clicked, this, &VisualizerWindow::onNextStepClicked);
    connect(exitButton, &QPushButton::clicked, this, &VisualizerWindow::onExitClicked);
    connect(helpButton, &QPushButton::clicked, this, &VisualizerWindow::onHelpClicked);
}

void VisualizerWindow::onNextStepClicked() {
    step++;
    glWidget->setStep(step);
    infoLabel->setText("Fractal: " + currentFractalType + " | Step: " + QString::number(step));
}

void VisualizerWindow::onExitClicked() {
    close();
}

void VisualizerWindow::onHelpClicked() {
    QString info = getFractalInfo(mapFractalNameToId(currentFractalType));
    QMessageBox::information(this, "Fractal Info", info);
}

QString VisualizerWindow::mapFractalNameToId(const QString &name) {
    if (name == "Дерево") return "Tree";
    if (name == "Снежинка Коха") return "Koch Snowflake";
    if (name == "Ковёр Серпинского") return "Sierpinski Carpet";
    if (name == "Спиральный фрактал") return "Spiral Fractal";
    if (name == "Фрактал Вичека") return "Vicsek Fractal";
    if (name == "H-фрактал") return "H-Fractal";
    if (name == "Кривая Леви") return "Levy C Curve";
    if (name == "Кривая Хильберта") return "Hilbert Curve";
    return name;
}

QString VisualizerWindow::getFractalInfo(const QString &type) {
    QString language = "English";
    QFile file("settings.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject obj = doc.object();
        language = obj["Language"].toString("English");
        file.close();
    }

    if (type == "Koch Snowflake") {
        return (language == "Русский") ?
            "Снежинка Коха строится путём рекурсивного добавления меньших равносторонних треугольников к каждой стороне." :
            "The Koch Snowflake is built by recursively adding smaller equilateral triangles to each side.";
    }
    if (type == "Tree") {
        return (language == "Русский") ?
            "Дерево-фрактал — это рекурсивная структура ветвления, напоминающая природное дерево." :
            "Tree Fractal is a recursive binary branching structure resembling a natural tree.";
    }
    if (type == "Sierpinski Carpet") {
        return (language == "Русский") ?
            "Ковёр Серпинского — двумерный фрактал, создаваемый удалением центрального квадрата из сетки." :
            "The Sierpinski Carpet is a 2D fractal made by repeatedly removing the central square from a grid.";
    }
    if (type == "Spiral Fractal") {
        return (language == "Русский") ?
            "Спиральный фрактал рисует спирали рекурсивно, создавая геометрическую воронку." :
            "The Spiral Fractal draws spirals recursively, creating a geometric swirl.";
    }
    if (type == "Vicsek Fractal") {
        return (language == "Русский") ?
            "Фрактал Вичека создаётся рекурсивным добавлением меньших крестов в виде креста." :
            "Vicsek Fractal is formed by recursively placing five smaller crosses in a cross pattern.";
    }
    if (type == "H-Fractal") {
        return (language == "Русский") ?
            "H-фрактал — геометрическая фигура, создаваемая размещением меньших H-образных структур по углам." :
            "H-Fractal is a geometric figure made by recursively placing smaller H-shapes at each corner.";
    }
    if (type == "Levy C Curve") {
        return (language == "Русский") ?
            "Кривая Леви создаётся путём рекурсивного изгиба отрезков под углом 45 градусов." :
            "Levy C Curve is formed by bending each line segment at a 45-degree angle recursively.";
    }
    if (type == "Hilbert Curve") {
        return (language == "Русский") ?
            "Кривая Хильберта — это заполняющая пространство кривая, которая рекурсивно изгибается для покрытия 2D-плоскости." :
            "The Hilbert Curve is a space-filling curve that recursively folds to cover a 2D space.";
    }

    return (language == "Русский") ? "Информация отсутствует." : "No information available.";
}
