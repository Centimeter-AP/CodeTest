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

    int N{}, M{};
    int iIter{};
    int a{}, b{};
    int res{};
    int dp[12] = {};

    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (size_t i = 0; i < N; i++)
    {
        cin >> M;
        if (M > 3)
        {
            for (size_t j = 4; j <= M; j++)
            {
                dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
            }
        }
        cout << dp[M] << '\n';
    }


    return 0;
}