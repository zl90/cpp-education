// https://usaco.org/index.php?page=viewproblem2&cpid=735

#include <bits/stdc++.h>
using namespace std;

auto has_found_bessie(int x, int y, int step) -> bool
{
    if (x == y)
    {
        return true;
    }
    else if (x > y)
    {
        return step + x <= y;
    }
    else
    {
        return step + x >= y;
    }
}

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    /*
        ~~~~~Desk checking:~~~~~

        -> sample input: 3 6
        -> expected: 9

        -----0--y--x-----
                   ^

        previous_step: 2
        step: 4
        distance: 4 + 2 + 3 = 9
    */

    int x, y;
    cin >> x >> y;

    int distance_travelled = 0;
    int step = 0;

    while (!has_found_bessie(x, y, step))
    {
        int previous_step = abs(step);

        if (step == 0)
        {
            step = 1;
        }
        else if (step > 0)
        {
            step *= -2;
        }
        else
        {
            step = abs(step) * 2;
        }

        if (has_found_bessie(x, y, step))
        {
            distance_travelled += abs(x - y) + previous_step;
            break;
        }

        distance_travelled += abs(step) + previous_step;
    }

    cout << distance_travelled;
}
