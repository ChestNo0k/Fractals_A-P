Это десктопное приложение для визуализации фракталов с графическим интерфейсом.

Системные требования

- ОС: Linux
- CMake 3.16+
- Qt6
- OpenGL

Установка зависимостей (Fedora)

Выполните в терминале:

sudo dnf install qt6-base-devel cmake mesa-libGL-devel

Ubunty/Debian:

sudo apt install qt6-base-devel cmake mesa-libGL-devel


Сборка и запуск

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

Главное окно

- Кнопка "Visualize" — запускает окно визуализации выбранного фрактала
- Кнопка "Exit" — завершает работу приложения
- Список "Fractal type" — выбор алгоритма фрактала (Tree, Koch, Carpet и т.д.)

Окно визуализации

- Кнопка "Next step" — отрисовывает следующий шаг фрактального алгоритма
- Кнопка "Exit" — закрывает окно
- В нижней части окна отображается:
  - Название фрактала
  - Текущий шаг визуализации
