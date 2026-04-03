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

    cin >> N >> M;
    vector<vector<int>> vecTable(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> vecSum(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> iIter;
            vecTable[i][j] = iIter;
            vecSum[i][j] = vecSum[i - 1][j] + vecSum[i][j - 1] - vecSum[i - 1][j - 1] + iIter;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1{}, y1{}, x2{}, y2{};
        cin >> x1 >> y1 >> x2 >> y2;

        cout << vecSum[x2][y2] - vecSum[x2][y1 - 1] - vecSum[x1 - 1][y2] + vecSum[x1 - 1][y1 - 1] << '\n';
    }


    return 0;
}