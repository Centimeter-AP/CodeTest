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
    vector<int> vecNum;
    vector<int> vecSum;

    cin >> N >> M;

    for (size_t i = 0; i < N; i++)
    {
        cin >> iIter;
        vecNum.push_back(iIter);
        if (i == 0) { vecSum.push_back(iIter); continue; }
        vecSum.push_back(vecSum[i - 1] + iIter);
    }

    for (size_t i = 0; i < M; i++)
    {
        res = 0;
        cin >> a >> b;
        if (a == b)
        {
            cout << vecNum[a - 1] << "\n";
            continue;
        }
        if (a != 1)
            cout << vecSum[b - 1] - vecSum[a - 2] << "\n";
        else
            cout << vecSum[b - 1] << "\n";
    }



    //cout << res;

    return 0;
}