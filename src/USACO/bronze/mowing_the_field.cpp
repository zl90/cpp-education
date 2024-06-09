// https://usaco.org/index.php?page=viewproblem2&cpid=593

/*
    SAMPLE INPUT:
    6
    N 10
    E 2
    S 3
    W 4
    S 5
    E 8
    SAMPLE OUTPUT:
    10
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<pair<int, int>, vector<int>> coords;
    coords[{0, 0}].emplace_back(0);

    int N;
    cin >> N;

    int current_x = 0;
    int current_y = 0;
    int current_time = 0;

    for (int n = 0; n < N; n++)
    {
        char direction;
        int steps;
        cin >> direction >> steps;

        for (int i = 0; i < steps; i++)
        {
            current_time++;
            switch (direction)
            {
            case 'N':
                current_y++;
                break;
            case 'S':
                current_y--;
                break;
            case 'E':
                current_x++;
                break;
            case 'W':
                current_x--;
                break;
            }
        }

        coords[{current_x, current_y}].emplace_back(current_time);
    }

    int x = -1;

    for (const auto &times_visited : coords)
    {
        if (times_visited.size() > 1)
        {
            int min_step = times_visited[1] - times_visited[0];

            if (x == -1)
            {
                x = min_step
            }

            for (int i = 1; i < times_visited.size(); i++)
            {
                int step = times_visited[i] - times_visited[i - 1];
                min_step = min(step, min_step)
            }

            x = min(x, min_step);
        }
    }

    cout << x;
}
