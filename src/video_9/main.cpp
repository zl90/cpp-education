#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>
#include <cassert>

using namespace std;

class IOException : public exception
{
public:
    int data;
    IOException(int id) : data(id) {}
    virtual const char *what() const throw()
    {
        return "Controller Error";
    }
};

float divide(float a, float b)
{
    try
    {
        if (b == 0.0)
        {
            throw("Error. Divided by zero");
        }
        else
        {
            return a / b;
        }
    }
    catch (char *error)
    {
        cout << error << endl;
    }
    catch (...)
    {
        cout << "Unkown error" << endl;
    }

    return -1;
}

int main()
{
    assert(1 < 2);

    cout << divide(4, 3) << endl;
    cout << divide(10, 0) << endl;

    IOException eio(100);

    try
    {
        throw(eio);
    }
    catch (IOException &e)
    {
        cout << e.what() << " Error number: " << e.data << endl;
    }

    return 0;
}