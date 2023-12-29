// Instructions:
// Find as many things wrong with the code as you can and fix them
// SortBySetBitCount is supposed to sort an array by the number of 1 (set) bits in the binary representation of each number
// Make it work correctly and as fast as possible
// You will be given points for style, speed and correctness

// space efficiency?
// sort in asc or desc?

#include <iostream>

unsigned int CountSetBits(unsigned int x)
{
	int result = 0;

	while (x != 0)
	{
        if (x & 1) {
		    result++;
        }

		x >>= 1;
	}

	return result;
}

void SortBySetBitCount(unsigned int* arr, int size)
{
    unsigned int aux[size];
    for (int i = 0; i < size; i++) {
        aux[i] = CountSetBits(arr[i]);
    }

	for (int i = 0; i < size; i += 1)
	{
		for (int j = i + 1; j < size; j += 1)
		{
			if ((aux[i]) <= (aux[j]))
			{
				unsigned int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

                temp = aux[i];
				aux[i] = aux[j];
				aux[j] = temp;
			}
		}
	}

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ", ";
    }

    std::cout << '\n';
}

int main () {
    const short size = 6;
    unsigned int myArray[size] = {1024, 88, 87, 99999, 45, 44};
    SortBySetBitCount(myArray, size);

    return 0;
}
