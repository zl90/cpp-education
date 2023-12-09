#include <iostream>

class Test {
    private:
    int arr [5];
    Test(){
        std::cout << "Instanciating Test object.\n";
        for (int i = 0; i < 5; i++) {
            arr[i] = i;
        }
    }

    public:
    static Test* initialize () {
        return new Test();
    }

    int& operator[](int i) { // Overloading array subscript operator
        return arr[i];
    }
};

int main () {
    Test * p = Test::initialize();
    int g = (*p)[2]; // caution: need to dereference the pointer first before using the array subscript operator

    std::cout << "p[2] = " << g << '\n';

    delete p;

    return 0;
}
