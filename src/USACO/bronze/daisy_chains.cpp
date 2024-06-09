// https://usaco.org/index.php?page=viewproblem2&cpid=1060

/*
    SAMPLE INPUT:
    4
    1 1 2 3

    --- DESK CHECKING:
    flowers: [1,1,2,3]
    i:          ^
    j:              ^
    count: 4
        curr_flowers: [1,2,4]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<float> flowers(N);

    for (auto &flower : flowers)
    {
        cin >> flower;
    }

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        count++; // Each photo of a single flower counts as an average
        vector<float> curr_flowers;
        curr_flowers.push_back(flowers[i]);

        for (int j = i + 1; j < N; j++)
        {
            curr_flowers.push_back(flowers[j]);
            float average = (float)accumulate(curr_flowers.begin(), curr_flowers.end(), 0) / curr_flowers.size();
            if (find(curr_flowers.begin(), curr_flowers.end(), average) != curr_flowers.end())
            {
                count++;
            }
        }

        curr_flowers.clear();
    }

    cout << count;
}
