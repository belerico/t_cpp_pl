/* 
    Open a file for writing (as an ofstream) and write a few hundred integers to it
*/

#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main()
{
    int n;
    complex<double> euler;
    const complex<double> i(0.0, 1.0);
    string to;

    cout << "How many numbers do you wanna write? ";
    cin >> n;
    cout << "Path of the output file: ";
    cin >> to;

    ofstream ofs{to};

    for (double j = 0; j < n; ++j)
    {
        euler = exp(i * j);
        ofs << to_string(int(euler.real() * 10.0 * (j / abs(j)))) << endl;
    }

    ofs.close();
}