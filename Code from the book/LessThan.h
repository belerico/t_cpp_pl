template <typename T>
class LessThan
{
private:
    T val;

public:
    LessThan(const T &x);
    ~LessThan();
    void set_val(T &x);
    T get_val();
    bool operator()(const T &x) { return x < val; }
};

template <typename T>
LessThan<T>::LessThan(const T &x) : val(x) {}

template <typename T>
LessThan<T>::~LessThan() { val = 0; }

template <typename T>
void LessThan<T>::set_val(T &x) { val = x; }

template <typename T>
T LessThan<T>::get_val() { return val; }