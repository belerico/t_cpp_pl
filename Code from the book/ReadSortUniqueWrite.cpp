#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string from, to;
    cout << "Path of the input file: ";
    cin >> from;
    cout << "Path of the output file: ";
    cin >> to;

    ifstream ifs{from};
    istream_iterator<string> ii{ifs};
    istream_iterator<string> eos{};

    ofstream ofs{to};
    ostream_iterator<string> oi{ofs, "\n"};

    vector<string> content{ii, eos};
    sort(content.begin(), content.end());

    unique_copy(content.begin(), content.end(), oi);

    return !ifs.eof() || !ofs;
}