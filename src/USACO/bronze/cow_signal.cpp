// https://usaco.org/index.php?page=viewproblem2&cpid=665

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int M, N, K;
    cin >> M >> N >> K;

    vector<string> signal{(size_t)M};
    fill(signal.begin(), signal.end(), "");

    getchar();

    for (int m = 0; m < M; m++)
    {
        int character;
        while ((character = getchar()) != '\n' && character != EOF)
        {
            signal[m] += (char)character;
        }
    }

    for (size_t m = 0; m < signal.size(); m++)
    {
        for (int x = 0; x < K; x++)
        {
            for (size_t n = 0; n < signal[m].size(); n++)
            {
                for (int k = 0; k < K; k++)
                {
                    cout << signal[m][n];
                }
            }

            if (!(m == M - 1 && x == K - 1))
            {
                cout << '\n';
            }
        }
    }
}
