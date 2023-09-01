## 1. Инициализируем репозиторий в папке с проектом
> git init<br>

## 2. Подключаем репозиторий pybind11 в качестве подмодуля
> git submodule add -b stable https://github.com/pybind/pybind11 extern/pybind11<br>
> git submodule update --init<br>

## 3. Пишем код модуля (_example.cpp_)
```
#include <pybind11/pybind11.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // опционально
    m.def("fibonacci", &fibonacci, "A function that calculates the Fibonacci sequence");
}
```

## 4. Пишем CMake-файл (_CMakeLists.txt_)
```
cmake_minimum_required(VERSION 3.27)
project(example)

add_subdirectory(extern/pybind11)
pybind11_add_module(example example.cpp)
```
## 5. Создаем папку build, заходим в нее и запускам генерацию проекта
> cmake ..<br>

## 6. Открываем проект (_example.sln_) в Visual Studio и собираем

## 7. Копируем из папки Release скомпилированное расширение (_example.cp311-win_amd64.pyd_) в папку с питоновским файлом и запускам
```
import example

def main():
    result = example.fibonacci(14)
    print(result)

if __name__ == "__main__":
    main()
```
