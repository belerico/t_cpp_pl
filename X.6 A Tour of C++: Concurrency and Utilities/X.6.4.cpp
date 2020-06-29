/*
    Repeat the histogram drawing example from §5.6.3 for a normal_distribution and 30
    rows.
*/

#include <iostream>
#include <map>
#include <random>

using namespace std;

class Rand_normal
{
public:
    Rand_normal() : dist{0.0, 1.0} {}
    Rand_normal(double mean, double stdev) : dist{mean, stdev} {}
    double operator()() { return dist(re); }

private:
    default_random_engine re;
    normal_distribution<double> dist;
};

int main()
{
    int n, factor;
    double mean, stdev;
    map<int, int> histogram;

    cout << "Insert the distribution mean: ";
    cin >> mean;
    cout << "Insert the distribution stdev: ";
    cin >> stdev;
    cout << "Insert the number of numbers you want to generate: ";
    cin >> n;
    cout << "Insert the number to factor the output histogram: ";
    cin >> factor;

    Rand_normal rn{mean, stdev};

    for (int i = 0; i < n; ++i)
        ++histogram[(int)round(rn())];
    for (auto p : histogram)
    {
        if (p.first >= 0)
            cout << ' ' << p.first << '\t';
        else
            cout << p.first << '\t';

        for (int j = 0; j < p.second / factor; ++j)
            cout << '*';
        cout << '\n';
    }
}