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

    vector<int> vecCoord;
    vector<int> vecCopy;
    vecCoord.reserve(1000000);
    vecCopy.reserve(1000000);
    cin >> N;

    while (N--)
    {
        cin >> iIter;
        vecCoord.push_back(iIter);
        vecCopy.push_back(iIter);
    }

    sort(vecCopy.begin(), vecCopy.end());
    vecCopy.erase(unique(vecCopy.begin(), vecCopy.end()), vecCopy.end());
    for (int i : vecCoord)
    {
        auto idx = lower_bound(vecCopy.begin(), vecCopy.end(), i) - vecCopy.begin();
        cout << idx << ' ';

    }


    return 0;
}