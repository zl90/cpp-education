

// Example: Smart pointer as a resource handle
#include <memory>

int main()
{
    std::unique_ptr<int> resourceHandle = std::make_unique<int>(42);
    return 0;
}
