#include <iostream>

template <typename T>
class Vector {
  T * elements;
  int size;

  public:
  explicit Vector(int a) { // constructor
    elements = new T[a];
    size = a;
  }

  explicit Vector(int a, T x) { // constructor
    elements = new T[a];
    size = a;

    for (int i = 0; i < size; i++) {
      elements[i] = x;
    }
  }

  ~Vector() { // destructor
    delete[] elements;
  }

  Vector<T>(const Vector<T>& obj) { // copy constructor
    size = obj.size;
    elements = new T[size];

    for (int i = 0; i < size; i++) {
      elements[i] = obj.elements[i];
    }
  }

  Vector<T>& operator=(const Vector<T>& obj) { // copy assignment operator override
    if (size > 0) {
      delete[] elements;
    }
    size = obj.size;
    elements = new T[size];

    for (int i = 0; i < size; i++) {
      elements[i] = obj.elements[i];
    }
    std::cout << "Copy assignment operator called!\n";
    return *this;
  }

  Vector<T>(Vector<T>&& obj) { // move constructor
    if (size > 0) {
      delete[] elements;
    }
    size = obj.size;
    elements = obj.elements;
    obj.size = 0;
    obj.elements = nullptr;
    std::cout << "Move constructor called!\n";
  }

  Vector<T>& operator=(Vector<T>&& obj) noexcept { // move assignment operator
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

  T& operator[](int i) { // array subscript overload 
    return elements[i];
  }

  const T& operator[](int i) const { // array subscript overload 
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

template <typename T>
T* begin(Vector<T>& x) { // iterator. This returns a pointer because the elements are allocated on the heap.
      return &x[0];
}

template <typename T>
T* end(Vector<T>& x) { // iterator
    return &x[0] + x.getSize(); // point to one past the last element of the vector
}

template <typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b) { // operator overload
  if (a.getSize() != b.getSize()) {
    throw "Vector size mismatch";
  }

  Vector<T> result(a.getSize());

  for (int i = 0; i < a.getSize(); i++) {
    result[i] = a[i] + b[i];
  }

  return result;
}

template <typename T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b) {
  if (a.getSize() != b.getSize()) {
    throw "Vector size mismatch";
  }

  Vector<T> result(a.getSize());

  for (int i = 0; i < a.getSize(); i++) {
    result[i] = a[i] - b[i];
  }

  return result;
}

int main () {
  Vector<double> v(5, 1);
  v.print();

  Vector<double> v2(v);
  Vector<double> v3 = v2;

  v2.print();
  v3.print();

  v2 = v;
  Vector<double> v4 = v2 + v3;
  v4 = v2 + v2 + v3;
  v4.print();

  Vector<double> v5 = v4 - v4;

  for (auto& x : v4) {
    std::cout << x << ". ";
  }
  std::cout << '\n';

  v5.print();

  Vector<char> v6(5, 'x');

  v6.print();

  return 0;
}
