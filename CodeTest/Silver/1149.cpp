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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N{};
    int iIter{};
    int res{};
    //vector<int> dp;
    int dp[1001][3];

    vector<array<int, 3>> house;

    cin >> N;

    int r, g, b;

    for (size_t i = 0; i < N; i++)
    {
        cin >> r >> g >> b;

        house.push_back({ r,g,b });
    }

    dp[0][0] = house.front()[0];
    dp[0][1] = house.front()[1];
    dp[0][2] = house.front()[2];

    int lastcolor{};
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2])
            + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2])
            + house[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0])
            + house[i][2];
    }

    cout << min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });


    return 0;
}