#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>
#include <thread>

template <typename T>
class Queue
{
public:
    auto Push(T element) -> void
    {
        std::unique_lock<std::mutex> lock(_mut);
        elements.push(element);
        lock.unlock();
        _cond.notify_one(); // Notifies the next waiting thread that the queue is not empty
    }

    auto Pop() -> T
    {
        std::unique_lock<std::mutex> lock(_mut);
        _cond.wait(lock, [this]
                   { return !elements.empty(); }); // Wait until notified the queue is not empty

        auto result = elements.front();
        elements.pop();
        return result;
    }

    auto Print() -> void
    {
        // Can't print a queue directly, so we make a copy of it then pop each element, printing them along the way
        std::unique_lock<std::mutex> lock(_mut);
        auto elements_copy = elements;

        while (!elements_copy.empty())
        {
            std::cout << elements_copy.front() << '\n';
            elements_copy.pop();
        }
    }

private:
    std::mutex _mut;               // For locking the critical section
    std::condition_variable _cond; // For notifying and waiting
    std::queue<T> elements{};
};

int main()
{
    Queue<int> q;
    q.Push(25);
    q.Push(35);
    q.Push(55);
    q.Pop();

    std::thread t1([&]()
                   { q.Push(22);
                    q.Pop(); });
    std::thread t2([&]()
                   { q.Push(11);
                   q.Pop();
                   q.Pop();
                   q.Pop();
                   q.Pop(); });

    std::thread t3([&]()
                   { q.Push(22);
                   q.Push(12); });

    t1.join();
    t2.join();
    t3.join();

    q.Print();

    return 0;
}
