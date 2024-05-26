#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

class Singleton {
 public:
  static auto GetInstance(int data) -> Singleton* {
    std::unique_lock<std::mutex> lock(mut_);
    if (instance_ == nullptr) {
      instance_ = new Singleton(data);
    }
    return instance_;
  }

  // Singleton should not be copyable:
  Singleton(const Singleton& obj) = delete;

  // Singleton should not be assignable:
  void operator=(const Singleton& obj) = delete;

  auto GetData() -> int { return data_; }

 private:
  Singleton(int data) {
    data_ = data;
  }  // Constructor must be private to prevent data_ being overwritten.

  static Singleton* instance_;
  static std::mutex mut_;
  int data_;
};

// Static data members must be initialised outside of the class.
Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mut_;

int main() {
  // Note: output should ONLY show the same number twice. If it shows two
  // different numbers, then the Singleton was instantiated twice (bad!)

  std::thread t1([]() {
    Singleton* s = Singleton::GetInstance(123);
    std::cout << s->GetData() << '\n';
  });
  std::thread t2([]() {
    Singleton* s = Singleton::GetInstance(444);
    std::cout << s->GetData() << '\n';
  });

  t1.join();
  t2.join();
}