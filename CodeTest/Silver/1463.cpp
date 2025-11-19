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

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{};
    int iIter{};
    int a{}, b{};
    int res{};
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    cin >> N;
    if (N < 4)
    {
        cout << dp[N];
    }
    else
    {
        for (size_t i = 4; i <= N; i++)
        {
            int s{};
            s = dp[i - 1];
            if (i % 2 == 0)
            {
                s = min(dp[i / 2], s);
            }
            if (i % 3 == 0)
            {
                s = min(dp[i / 3], s);
            }
            dp[i] = s + 1;
        }
        cout << dp[N];
    }

    return 0;
}