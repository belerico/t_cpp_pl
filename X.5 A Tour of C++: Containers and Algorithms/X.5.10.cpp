/* 
    Open the file of integers from §X.5[9] for reading (as an ifstream) and read it
*/

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main()
{
    char c;
    string from, line;
    cout << "Path of the input file: ";
    cin >> from;

    ifstream ifs{from};

    while (!ifs.eof())
    {
        while (ifs.get(c) && c != '\n') 
            line += c;
        cout << line << endl;
        line = "";
    }
}