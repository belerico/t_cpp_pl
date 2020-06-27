/* 
    Write a program that reads a name (a string) and an age (an int) from the standard
    input stream cin. Then output a message including the name and age to the standard output
    stream cout.
 */

#include <string>
#include <iostream>
using namespace std;

int main()
{
    int age;
    string name;
    cout << "Insert your name: ";
    getline(cin, name);

    cout << "Insert your age: ";
    cin >> age;

    cout << "Welcome " << name << ", you've correctly input your age (" << age << "): what a success!" << endl;
}
