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

int N;
int res;
void NQueen(vector<int> pos, int idx);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    res = 0;
    cin >> N;

    vector<int> pos(N, -1);
    //pos.reserve(N);
    for (int i = 0; i < N; i++)
    {
        pos[0] = i;
        NQueen(pos, 1);
    }

    cout << res;

    return 0;
}

void NQueen(vector<int> pos, int idx)
{
    if (idx == N)
    {
        res++;
        return;
    }
    for (int i = 0; i < N; i++) // i == x, pos[j] == x
    {
        bool safe = true;
        for (int j = 0; j < idx; j++) // j == y, idx == y
        {
            if (i == pos[j] || abs(j - idx) == abs(i - pos[j])) // 대각
            {
                safe = false;
                break;
            }
        }
        if (safe)
        {
            pos[idx] = i;
            NQueen(pos, idx + 1);
        }
    }
}