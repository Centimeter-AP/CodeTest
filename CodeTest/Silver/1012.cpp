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

int cab[50][50];
int res{};

void bfs(queue<pair<int, int>>* next, const int& N, const int& M);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{}, K{};
    int iIter{};
    int a{}, b{};

    int T{};

    cin >> T;

    while (T--)
    {
        queue<pair<int, int>> next;
        memset(cab, 0, sizeof(int) * 50 * 50);
        res = 0;
        cin >> M >> N >> K;
        int x{}, y{};
        while (K--)
        {
            cin >> x >> y;
            cab[y][x] = 1;
        }
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                if (cab[i][j] == 1)
                {
                    next.push({ i,j });
                    ++res;
                    bfs(&next, N, M);
                }
            }
        }
        cout << res << '\n';
    }


    return 0;
}

void bfs(queue<pair<int, int>>* next, const int& N, const int& M)
{
    if (next->empty())
        return;
    int x{}, y{};
    x = next->front().second;
    y = next->front().first;
    next->pop();

    if (x + 1 < M && cab[y][x + 1] == 1)
    {
        ++cab[y][x + 1];
        next->push({ y, x + 1});
    }
    if (x - 1 >= 0 && cab[y][x - 1] == 1)
    {
        ++cab[y][x - 1];
        next->push({ y, x - 1});
    }
    if (y + 1 < N && cab[y + 1][x] == 1)
    {
        ++cab[y + 1][x];
        next->push({ y + 1, x});
    }
    if (y - 1 >= 0 && cab[y - 1][x] == 1)
    {
        ++cab[y - 1][x];
        next->push({ y - 1, x });
    }

    if (!next->empty())
        bfs(next, N, M);
}