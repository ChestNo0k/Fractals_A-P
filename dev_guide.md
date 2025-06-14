

# Руководство разработчика

## Введение

Это десктопное приложение, реализованное на C++ с использованием Qt6 и OpenGL. Оно предназначено для пошаговой визуализации различных фрактальных алгоритмов, с возможностью переключения языка и темы интерфейса.

![img](sticker.gif)

## Архитектура проекта

Fractals_A-P/

├── CMakeLists.txt             # Главный CMake-файл сборки проекта

├── main.cpp                   # Точка входа в приложение

├── settings.json              # Конфигурация (язык, тема, размер окна)

├── src/

│   ├── core/                  # Реализация фрактальных алгоритмов

│   │   ├── Fractal.h

│   │   ├── TreeFractal.*

│   │   ├── KochFractal.*

│   │   ├── SierpinskiCarpet.*

│   │   ├── SpiralFractal.*

│   │   ├── VicsekFractal.*

│   │   ├── HFractal.*

│   │   ├── LevyFractal.*

│   │   └── HilbertFractal.*

│

│   ├── gui/

│   │   ├── MainWindow.*       # Главное окно с выбором фрактала и кнопками

│   │   ├── VisualizerWindow.*# Окно отрисовки фрактала и интерфейс

│   │   └── SettingsWindow.*  # Окно для выбора языка, темы и размера

│

│   ├── widgets/

│   │   └── FractalGLWidget.* # OpenGL-виджет для пошаговой отрисовки

## Описание расширения проекта

Чтобы добавить новый фрактал:

1. Создайте новый класс в `src/core/`, унаследованный от `Fractal`.
2. Реализуйте в нём метод `void draw(int step) override`.
3. В `VisualizerWindow.cpp`:
   - Добавьте `#include "core/YourNewFractal.h"`
   - В функции `mapFractalNameToId()` добавьте соответствие имени на русском и английском к внутреннему ID
   - В логике выбора `if (id == "...")` добавьте `glWidget->setFractal(std::make_unique<...>());`
4. Добавьте названия в `MainWindow.cpp`:
   - В `applyLanguage()` добавьте строки `fractalComboBox->addItem(...)` для русского и английского языков

## Интернационализация

Язык интерфейса выбирается автоматически на основе поля `"Language"` из файла `settings.json` (`"English"` или `"Русский"`). Переводы поддерживаются в `MainWindow`, `VisualizerWindow`, `SettingsWindow`.

## Темы оформления

Поле `"Theme"` в `settings.json` может принимать значения `"Light"` или `"Dark"`. Для тёмной темы применяется глобальный стиль Qt.

## Руководство пользователя

### Сборка проекта

```bash
mkdir build
cd build
cmake ..
make
```


### Пересборка проекта

```bash
make rebuild
```

*(если цель `rebuild` добавлена в `CMakeLists.txt`)*

### Запуск

```bash
./FractalsApp
```

### Настройки

Изменение языка, темы и разрешения окна производится через интерфейс `Settings`, настройки сохраняются в `settings.json`, для применения требуется перезапуск приложения.

```

```
