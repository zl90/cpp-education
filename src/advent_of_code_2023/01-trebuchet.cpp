#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("01-trebuchet-input");

    if (!file.is_open())
    {
        std::cerr << "Error opening the file." << '\n';
        return 1;
    }

    auto total{0};
    std::string line;

    while (std::getline(file, line))
    {
        auto first{0}, last{0};

        for (auto character : line)
        {
            if (character >= 49 && character <= 57)
            {
                if (first == 0)
                {
                    first = character - 48;
                }

                last = character - 48;
            }
        }

        total += (first * 10) + last;
    }

    std::cout << "Total: " << total << '\n';

    file.close();

    return 0;
}