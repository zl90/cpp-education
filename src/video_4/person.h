#pragma once
#include <iostream>

using namespace std;

// Exercise 1:
class Person
{
public:
    Person() {}

    void Crawl()
    {
        cout << "Crawling" << endl;
    }

    void Stand()
    {
        cout << "Standing" << endl;
    }

    void Walk()
    {
        cout << "Walking" << endl;
    }

    void Run()
    {
        cout << "Running" << endl;
    }
};