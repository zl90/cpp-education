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

    int& operator[](int i) {
        return arr[i];
    }
};

enum class Color {
    red,
    blue,
    yellow
};

int main () {
    Test * p = Test::initialize();
    int g = (*p)[2];

    std::cout << "p[2] = " << g << '\n';

    delete p;

    Color r = Color::red;

    std::cout << (int)r << '\n';

}
