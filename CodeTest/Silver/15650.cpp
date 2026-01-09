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

int N, M;
void BT(int res[8], int idx);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int iIter{};
    int a{}, b{};
    int res[8] = {};
    //res[0] = 1;

    cin >> N >> M;

    BT(res, 0);

    return 0;
}

void BT(int res[8], int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < idx; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int start{1};
    if (idx != 0)
        start = res[idx - 1] + 1;

    for (int i = start; i <= N; i++)
    {
        res[idx] = i;
        BT(res, idx + 1);
    }
}