/*
    Use a regex to find all decimal numbers in a file.
*/

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string bold_red = "\033[1m\033[31m", reset = "\033[0m", path;
    regex decimal_pattern("((\\+|-)?\\d+\\.\\d+)");
    sregex_iterator empty{};
    smatch last;

    cout << "Insert the file path: ";
    cin >> path;

    ifstream ifs{path};

    if (ifs) {
        for (string line; getline(ifs, line);)
        {
            sregex_iterator p(line.begin(), line.end(), decimal_pattern);
            if (p != empty)
            {
                for (; p != empty; ++p)
                {
                    last = (*p);
                    cout << (*p).prefix() << bold_red << (*p)[1] << reset;
                }
                cout << last.suffix() << endl;
            }
            else
                cout << line << endl;
        }
    }
    else
        cerr << "Error reading file: " << path << endl;
}
