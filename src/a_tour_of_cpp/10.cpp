#include <string>
#include <iostream>
#include <regex>

std::regex pattern{"\\w{2}\\s*\\d{5}(-\\d{4})?"};

int main()
{
    int line_number = 0;
    for (std::string line; std::getline(std::cin, line);)
    {
        ++line_number;
        std::smatch matches;
        if (std::regex_search(line, matches, pattern))
        {
            for (std::string match : matches)
            {
                std::cout << line_number << ": " << match << '\n';
            }
        }
    }

    return 0;
}
