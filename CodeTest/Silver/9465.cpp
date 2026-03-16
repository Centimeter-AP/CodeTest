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

int dp[100001][3]; // 0안고름1고름2고름.. 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{};
    int iIter{};
    vector<vector<int>> sticker;
    sticker.reserve(2);
    cin >> N;


    for (int i = 0; i < N; i++)
    {
        cin >> M;
        for (int k = 0; k < 2; ++k)
        {
            vector<int> line;
            line.reserve(M);
            for (int j = 0; j < M; j++)
            {
                cin >> iIter;
                line.push_back(iIter);
            }
            sticker.push_back(line);
        }
        dp[0][0] = 0;
        dp[0][1] = sticker[0][0];
        dp[0][2] = sticker[1][0];
        for (int i = 1; i < M; i++)
        {
            dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + sticker[0][i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + sticker[1][i];
        }
        cout << max({ dp[M - 1][0], dp[M - 1][1], dp[M - 1][2] }) << '\n';
        sticker.clear();
    }

    //dp[0][0] = 0;
    //dp[0][1] = sticker[0][0];
    //dp[0][2] = sticker[0][1];
    //dp[1][0] = max(dp[0][0], dp[0][1], dp[0][2]);
    //dp[1][1] = max(dp[0][0], dp[0][2]) + sticker[1][1];
    //dp[1][2] = max(dp[0][0], dp[0][1]) + sticker[1][2];




    return 0;
}