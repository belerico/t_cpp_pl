/* 
    Repeat §X.5[7] with a vector<string> initialized with "Kant", "Plato", "Aristotle",
    "Kierkegard", and "Hume"
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v{"Kant", "Plato", "Aristotle",
                     "Kierkegard", "Hume"};
    cout << "v before sorting: ";
    for (auto &x : v)
        cout << x << " ";
    sort(v.begin(), v.end());
    cout << endl
         << "v after sorting: ";
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}