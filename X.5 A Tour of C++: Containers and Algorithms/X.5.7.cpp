/* 
    Initialize a vector<int> with the elements 5, 9, −1, 200, and 0. 
    Print it. Sort it, and print it again
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{5, 9, -1, 200, 0};
    cout << "v before sorting: ";
    for (auto &x: v)
        cout << x << " ";
    sort(v.begin(), v.end());
    cout << endl << "v after sorting: ";
    for (auto &x: v)
        cout << x << " ";
    cout << endl;
}