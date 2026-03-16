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

    vector<vector<int>> vecTable;
    vector<vector<int>> vecSum;

    cin >> N >> M;
    vecTable.reserve(N);
    vecSum.reserve(N);
    for (int i = 0; i < N; i++)
    {
        vector<int> vecRow;
        vector<int> vecSumRow;
        vecRow.reserve(N);
        vecSumRow.reserve(N);
        for (int j = 0; j < N; j++)
        {
            cin >> iIter;
            vecRow.push_back(iIter);
            if (!i && !j) vecSumRow.push_back(iIter);
            //else vecSumRow.push_back(vecSum[] + iIter); 2차원누적합계산식생각할것..
        }
        vecTable.push_back(vecRow);
    }

    for (int i = 0; i < M; i++)
    {
        int x1{}, y1{}, x2{}, y2{};
        cin >> x1 >> y1 >> x2 >> y2;
    }

    return 0;
}