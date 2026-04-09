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
using pii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    string A, B;
    
    cin >> A >> B;
    
    int iASize{(int)A.size()};
    int iBSize{(int)B.size()};
    
    vector<vector<int>> dp(iBSize+1, vector<int>(iASize+1, 0));

    for (int i = 1; i < iBSize+1; i++)
    {
        for (int j = 1; j < iASize+1; j++)
        {
            if (A[j - 1] == B[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[iBSize][iASize];

    return 0;
}