#include <fill/fill.h>

template<typename T>
void fill(std::vector<T>& a, T value) {
    for (auto& element : a) {
        element = value;
    }
}

template void fill<int>(std::vector<int>& a, int value);

template void fill<float>(std::vector<float>& a, float value);

template void fill<double>(std::vector<double>& a, double value);