/*
    Write a program with two treads: one that writes hello every second and one that
    writes world! every second.
*/

#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
using namespace std;

mutex print_mutex;

void thread_print(string &msg)
{
    while (true)
    {
        unique_lock<mutex> lock(print_mutex);
        cout << "I'm thread number: " << this_thread::get_id() << endl;
        cout << msg << endl;
        cout << "Now I'm going to sleep for 1 sec" << endl;
        lock.unlock();
        this_thread::sleep_for(1s);
    }
}

int main()
{
    string msg1 = "Hello";
    string msg2 = "world!";

    thread t1{thread_print, ref(msg1)};
    thread t2{thread_print, ref(msg2)};

    t1.join();
    t2.join();
}