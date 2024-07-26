#include <inner_product/inner_product.h>
#include <stdexcept>

template<typename T>
T inner_product(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) {
        throw std::runtime_error("The two vectors are not equal length.");
    }
    T result = 0;
    for (int i = 0; i < a.size(); i++) {
        result += a[i] * b[i];
    }
    return result;
}

template int inner_product<int>(const std::vector<int>& a, const std::vector<int>& b);
template float inner_product<float>(const std::vector<float>& a, const std::vector<float>& b);
template double inner_product<double>(const std::vector<double>& a, const std::vector<double>& b);