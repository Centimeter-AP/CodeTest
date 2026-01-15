#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <list>
#include <queue>
#include <array>
#include <cstring>
#include <sstream>

using namespace std;
int pyramid[501][501]{};
int dp[501][501]{};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N{};
    int res{};
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < i + 1; j++)
        {
            cin >> pyramid[i][j];
        }
    }   


    dp[0][0] = pyramid[0][0];
    dp[1][0] = dp[0][0] + pyramid[1][0];
    dp[1][1] = dp[0][0] + pyramid[1][1];

    for (size_t i = 2; i < N; i++)
    {
        dp[i][0] = dp[i - 1][0] + pyramid[i][0];
        for (size_t j = 1; j < i + 1; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + pyramid[i][j];
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        res = max(dp[N - 1][i], res);
    }
    cout << res;
    return 0;
}