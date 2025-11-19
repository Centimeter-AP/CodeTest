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


void BT(int* res, int idx, int N, int M)
{
    for (size_t i = 1; i <= N; i++)
    {
        size_t j{};
        for (j = 0; j < idx; j++)
        {
            if (res[j] == i)
                break;
        }
        if (j == idx)
        {
            res[j] = i;
        }
        else
            continue;
        if (idx + 1 == M)
        {
            for (size_t k = 0; k < M; k++)
            {
                cout << res[k] << ' ';
            }
            cout << '\n';
            res[M - 1] = 0;
            continue;
        }
        else
            BT(res, idx + 1, N, M);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{};
    int iIter{};
    int a{}, b{};


    cin >> N >> M;

    int res[8] = { 0, };

    BT(res, 0, N, M);

    return 0;
}