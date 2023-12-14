#include <iostream>

class Vector {
  double * elements;
  int size;

  public:
  explicit Vector(int a) { // constructor
    elements = new double[a];
    size = a;

    for (int i = 0; i < size; i++) {
      elements[i] = 1;
    }
  }

  ~Vector() { // destructor
    delete[] elements;
  }

  Vector(const Vector& obj) { // copy constructor
    size = obj.size;
    elements = new double[size];

    for (int i = 0; i < size; i++) {
      elements[i] = obj.elements[i];
    }
  }

  Vector& operator=(const Vector& obj) { // copy assignment operator override
    if (size > 0) {
      delete[] elements;
    }
    size = obj.size;
    elements = new double[size];

    for (int i = 0; i < size; i++) {
      elements[i] = obj.elements[i];
    }
    std::cout << "Copy assignment operator called!\n";
    return *this;
  }

  Vector(Vector&& obj) { // move constructor
    if (size > 0) {
      delete[] elements;
    }
    size = obj.size;
    elements = obj.elements;
    obj.size = 0;
    obj.elements = nullptr;
    std::cout << "Move constructor called!\n";
  }

  Vector& operator=(Vector&& obj) noexcept { // move assignment operator
    if (this != &obj) {
      delete[] elements;

      size = obj.size;
      elements = obj.elements;

      obj.size = 0;
      obj.elements = nullptr;

      std::cout << "Move assignment operator called!\n";
    }
    return *this;
  }

  double& operator[](int i) { // array subscript overload 
    return elements[i];
  }

  const double& operator[](int i) const { // array subscript overload 
    return elements[i];
  }

  void print() {
    for (int i = 0; i < size; i++) {
      std::cout << elements[i] << ", ";
    }
    std::cout << '\n';
  }

  int getSize() const { return size; }
};

Vector operator+(const Vector& a, const Vector& b) { // operator overload
  if (a.getSize() != b.getSize()) {
    throw "Vector size mismatch";
  }

  Vector result(a.getSize());

  for (int i = 0; i < a.getSize(); i++) {
    result[i] = a[i] + b[i];
  }

  return result;
}

int main () {
  Vector v(5);
  v.print();

  Vector v2(v);
  Vector v3 = v2;

  v2.print();
  v3.print();

  v2 = v;
  Vector v4 = v2 + v3;
  v4 = v2 + v2 + v3;
  v4.print();

  return 0;
}
