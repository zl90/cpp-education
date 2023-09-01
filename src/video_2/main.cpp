#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    srand(time(NULL)); // Seed the random number generator.

    while (true)
    {
        int arr[] = {1, 2, 3, 4, 5}; // Initialise arrays
        for (int i : arr)
        {
            cout << i << " ";
        }

        cout << endl;
        cout << *arr << endl;       // Dereferencing the array points to the first element in the array
        cout << *(arr + 1) << endl; // Arrays are contiguous in memory, so you can access them via pointer arithmetic

        int board[8][8]; // Multidimensional arrays
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = 0;
            }
        }

        // enums:
        enum CertificationLevels
        {
            ECT,
            Trainee,
            Diploma
        };

        cout << Trainee << endl;

        // Random numbers:
        cout << "A random number: " << rand() << endl;
        cout << "A smaller random number: " << rand() % 10 << endl;

        int option;
        cout << "Enter your preferred means of transport (1..3): ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Go by bus" << endl;
            break;
        case 2:
            cout << "Go by train" << endl;
            break;
        case 3:
            cout << "Go by plane" << endl;
            break;
        default:
            cout << "Invalid option selected" << endl;
        }
    }

    return 0;
}