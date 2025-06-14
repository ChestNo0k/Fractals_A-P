Fractals_A-P

Это десктопное приложение для пошаговой визуализации фракталов с графическим интерфейсом на Qt6 и OpenGL.

Системные требования:

- ОС: Linux
- C++17
- CMake 3.16+
- Qt6 (qt6-base)
- OpenGL

Установка зависимостей

Fedora:
sudo dnf install qt6-base-devel cmake mesa-libGL-devel

Ubuntu / Debian:
sudo apt install qt6-base-dev cmake libgl1-mesa-dev

Сборка и запуск:

1. Клонируйте репозиторий:
   git clone https://github.com/ChestNo0k/Fractals_A-P.git

2. Перейдите в директорию и создайте сборочную папку:
   cd Fractals_A-P
   mkdir build && cd build
   cmake ..
   make

3. Запустите приложение:
   ./FractalsApp

Описание интерфейса:

Главное окно:
- Список "Fractal type" — выбор алгоритма фрактала (Tree, Koch, Carpet и др.)
- Кнопка "Visualize" — открыть окно визуализации
- Кнопка "Settings" — изменить тему, язык и разрешение
- Кнопка "Exit" — выйти из приложения

Окно визуализации:
- Кнопка "Next" — нарисовать следующий шаг
- Кнопка "?" — показать описание текущего фрактала
- Кнопка "Exit" — закрыть окно
- Внизу отображаются: название фрактала и текущий шаг

Настройки сохраняются в файле `settings.json`.

Языки интерфейса: English, Русский
Темы: Light, Dark
