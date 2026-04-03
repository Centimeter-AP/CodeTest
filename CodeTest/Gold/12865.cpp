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
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, K{};

    cin >> N >> K;

    vector<pair<int, int>> Items(N + 1, { 0,0 });
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    // weight, value

    for (int i = 1; i <= N; i++)
    {
        cin >> Items[i].first >> Items[i].second;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (Items[i].first > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], Items[i].second + dp[i - 1][j - Items[i].first]);
            }
        }

    }

    cout << dp[N][K];

    return 0;
}