#include <iostream>
using namespace std;

class Vector
{
public:
    Vector(int s);
    Vector(double *d, int s);
    Vector(initializer_list<double> lst);
    Vector(const Vector &v);
    ~Vector();
    void push_back(double d);
    double &operator[](int i);
    Vector &operator=(const Vector &v);
    int size() const;

    friend ostream &operator<<(ostream &strm, Vector &v);

private:
    double *elem;
    int sz;
};