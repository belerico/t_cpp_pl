#include <vector>

template <typename T>
class RangeCheckVec : public std::vector<T>
{
public:
    using vector<T>::vector; // Use same constructor as vector with RangeCheckVec()

    T &operator[](int i) { return vector<T>::at(i); }

    const T &operator[](int i) const { return vector<T>::at(i); }
};