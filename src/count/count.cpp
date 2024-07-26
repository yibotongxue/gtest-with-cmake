#include <count/count.h>

template<typename T>
int count(const std::vector<T>& a, T value) {
    int sum = 0;
    for (const T& num : a) {
        if (num == value) {
            sum += 1;
        }
    }
    return sum;
}

template int count<int>(const std::vector<int>& a, int value);

template int count<float>(const std::vector<float>& a, float value);

template int count<double>(const std::vector<double>& a, double value);