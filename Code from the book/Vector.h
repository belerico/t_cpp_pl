#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:
    Vector(int s);
    Vector(T *d, int s);
    Vector(initializer_list<T> lst);
    Vector(const Vector<T> &v); // copy constructor
    Vector(Vector<T> &&v);      // move constructor
    ~Vector();
    void push_back(T d);
    T &operator[](int i);
    Vector<T> &operator=(const Vector<T> &v); // copy assignment
    Vector<T> &operator=(Vector<T> &&v);      // move assignment
    int size() const { return sz; };

private:
    T *elem;
    int sz;
};

template <typename T>
Vector<T>::Vector(int s)
{
    if (s < 0)
        throw length_error{"Vector size must be a non negative number"};
    elem = new T[s];
    sz = s;
}

template <typename T>
Vector<T>::Vector(T *d, int s)
{
    if (s < 0)
        throw length_error{"Vector size must be a non negative number"};
    elem = new T[s];
    sz = s;
    for (int i = 0; i < s; ++i)
        elem[i] = d[i];
}

template <typename T>
Vector<T>::Vector(initializer_list<T> lst)
{
    elem = new T[lst.size()];
    sz = static_cast<int>(lst.size());
    copy(lst.begin(), lst.end(), elem);
}

template <typename T>
Vector<T>::Vector(const Vector &v) : elem{new T[v.sz]}, sz{v.sz} // copy constructor
{
    for (int i = 0; i < sz; ++i)
        elem[i] = v.elem[i];
}

template <typename T>
Vector<T>::Vector(Vector &&v) : elem{v.elem}, sz{v.sz} // move constructor
{
    v.elem = nullptr;
    v.sz = 0;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] elem;
    sz = 0;
}

// Vector read(istream &is)
// {
//     Vector v{};
//     for (T d; is >> d;)
//         v.push_back(d);
//     return v;
// }

template <typename T>
T &Vector<T>::operator[](int i)
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Index out of range"};
    return elem[i];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v) // copy assignment
{
    T *p = new T[v.sz];
    for (int i = 0; i < v.sz; ++i)
        p[i] = v.elem[i];
    delete[] elem;
    elem = p;
    sz = v.sz;
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&v) // move assignment
{
    elem = v.elem;
    v.elem = nullptr;
    sz = v.sz;
    v.sz = 0;
    return *this;
}

template <typename T>
Vector<T> operator+(Vector<T> &v1, Vector<T> &v2)
{
    if (v1.size() != v2.size())
        throw length_error{"Vector's lenght differs"};

    Vector<T> res(v1.size());
    for (int i = 0; i < v1.size(); ++i)
        res[i] = v1[i] + v2[i];
    return res;
}

template <typename T>
ostream &operator<<(ostream &strm, Vector<T> &v)
{
    strm << '[';
    // for (int i = 0; i < v.size(); ++i)
    //     strm << v[i] << ", ";
    for (T x : v)
        strm << x << ", ";
    strm << ']';
    return strm;
}

template <typename T>
T *begin(Vector<T> &v)
{
    return v.size() ? &v[0] : nullptr;
}

template <typename T>
T *end(Vector<T> &v)
{
    return v.size() + begin(v);
}