/* 
    Read in a bool, a char, an int, a double, and a string
 */

#include <iostream>
#include <string>

int main()
{
    bool b;
    std::cout << "Insert a boolean: ";
    std::cin >> b;
    
    char c;
    std::cout << "Insert a char: ";
    std::cin >> c;

    int i;
    std::cout << "Insert an int: ";
    std::cin >> i;

    double d;
    std::cout << "Insert a double: ";
    std::cin >> d;

    std::string s;
    std::cout << "Insert a string: ";
    std::cin >> s;
}