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
