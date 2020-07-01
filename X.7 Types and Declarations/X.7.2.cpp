/* 
    Write a program that prints signed if plain chars are signed on your implementation and
    unsigned otherwise.
*/

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    char c = 255;
    int i = c;
    
    if (i == 255)
        cout << "Unsigned chars (from numerical checking)" << endl;
    else
        cout << "Signed chars (from numerical checking)" << endl;

    if (!numeric_limits<char>::is_signed)
        cout << "Unsigned chars (from limits.h)" << endl;
    else
        cout << "Signed chars (from limits.h)" << endl;
}