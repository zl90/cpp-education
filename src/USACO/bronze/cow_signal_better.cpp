// https://usaco.org/index.php?page=viewproblem2&cpid=665

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int M, N, K;
    cin >> M >> N >> K;

    for (int m = 0; m < M; m++)
    {
        string input_line;
        cin >> input_line;
        string output_line = "";
        for (int n = 0; n < input_line.size(); n++)
        {
            for (int k = 0; k < K; k++)
            {
                output_line += input_line[n];
            }
        }

        for (int k = 0; k < K; k++)
        {
            cout << output_line << '\n';
        }
    }
}
