#include <iostream>
#include <fstream>
#include <string>

void updateFirstAndLast(auto &first, auto &last, int newValue)
{
    if (first == 0)
    {
        first = newValue;
    }

    last = newValue;
}

void checkLastThreeCharacters(auto &first, auto &last, const auto &buffer)
{
    if (buffer == "one")
    {
        updateFirstAndLast(first, last, 1);
    }
    else if (buffer == "two")
    {
        updateFirstAndLast(first, last, 2);
    }
    else if (buffer == "six")
    {
        updateFirstAndLast(first, last, 6);
    }
}

void checkLastFourCharacters(auto &first, auto &last, const auto &buffer)
{
    auto lastThreeChars = buffer.substr(1, 3);

    checkLastThreeCharacters(first, last, lastThreeChars);

    if (buffer == "four")
    {
        updateFirstAndLast(first, last, 4);
    }
    else if (buffer == "five")
    {
        updateFirstAndLast(first, last, 5);
    }
    else if (buffer == "nine")
    {
        updateFirstAndLast(first, last, 9);
    }
}

void checkLastFiveCharacters(auto &first, auto &last, const auto &buffer)
{
    auto lastThreeChars = buffer.substr(buffer.length() - 3, 3);
    auto lastFourChars = buffer.substr(buffer.length() - 4, 4);
    auto lastFiveChars = buffer.substr(buffer.length() - 5, 5);

    checkLastThreeCharacters(first, last, lastThreeChars);
    checkLastFourCharacters(first, last, lastFourChars);

    if (lastFiveChars == "three")
    {
        updateFirstAndLast(first, last, 3);
    }
    else if (lastFiveChars == "seven")
    {
        updateFirstAndLast(first, last, 7);
    }
    else if (lastFiveChars == "eight")
    {
        updateFirstAndLast(first, last, 8);
    }
}

int main()
{
    std::ifstream file("01-trebuchet-input");

    if (!file.is_open())
    {
        std::cerr << "Error opening the file." << '\n';
        return 1;
    }

    auto total{0};
    std::string line, buffer;

    while (std::getline(file, line))
    {
        auto first{0}, last{0};

        for (auto character : line)
        {
            if (character >= 49 && character <= 57)
            {
                updateFirstAndLast(first, last, character - 48);
                buffer = "";
            }
            else
            {
                buffer += character;

                if (buffer.length() == 3)
                {
                    checkLastThreeCharacters(first, last, buffer);
                }
                else if (buffer.length() == 4)
                {
                    checkLastFourCharacters(first, last, buffer);
                }
                else if (buffer.length() > 4)
                {
                    checkLastFiveCharacters(first, last, buffer);
                }
            }
        }

        total += (first * 10) + last;
    }

    std::cout << "Total: " << total << '\n';

    file.close();

    return 0;
}