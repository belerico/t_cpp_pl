/*
    Time a loop. Write out the time in milliseconds. Do this for the default setting of your
    compiler and for a setting using an optimizer (e.g., −O2 or "release"). Be careful not to have
    the optimizer eliminate your whole loop as dead code because you did not use a result
*/

#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    char c;
    string from, line;
    cout << "Path of the input file: ";
    cin >> from;

    ifstream ifs{from};

    cout << "Reading file: " << from << endl;
    auto init = chrono::high_resolution_clock::now();
    while (!ifs.eof())
    {
        while (ifs.get(c) && c != '\n')
            line += c;
        line = "";
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Done!" << endl;
    cout << "Time elapsed: " << chrono::duration_cast<chrono::nanoseconds>(end - init).count() << " ns" << endl;
}