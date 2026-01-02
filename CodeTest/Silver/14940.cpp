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

int arrMap[1001][1001];
int arrRes[1001][1001];
bool arrVisited[1001][1001];

typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.
    memset(arrVisited, false, sizeof(bool) * 1001 * 1001);
    memset(arrRes, -1, sizeof(int) * 1001 * 1001);

    int N{}, M{};
    int iIter{};

    queue<pii> qBFS;

    cin >> N >> M;


    for (size_t i = 0; i < N * M; i++)
    {
        cin >> arrMap[i / M][i % M];
        if (arrMap[i / M][i % M] == 2)
        {
            qBFS.push({ i % M ,i / M });
            arrRes[i / M][i % M] = 0;
            arrVisited[i / M][i % M] = true;
        }
        if (arrMap[i / M][i % M] == 0)
        {
            arrRes[i / M][i % M] = 0;
            arrVisited[i / M][i % M] = true;
        }
    }

    while (!qBFS.empty())
    {
        pii idx = qBFS.front(); qBFS.pop();
        int y = idx.second;
        int x = idx.first;
        int dist = arrRes[y][x];

        if (x >= 10 && y >= 11)
            int a = 0;
        //arrRes[y][x] = dist;
        if (x + 1 < M && !arrVisited[y][x+1]) {
            qBFS.push({ x + 1, y });
            arrVisited[y][x + 1] = true;
            arrRes[y][x + 1] = dist + 1;
        }
        if (x - 1 >= 0 && !arrVisited[y][x - 1]) {
            qBFS.push({ x - 1, y });
            arrVisited[y][x - 1] = true;
            arrRes[y][x - 1] = dist + 1;
        }
        if (y + 1 < N && !arrVisited[y + 1][x]) {
            qBFS.push({ x, y + 1 });
            arrVisited[y + 1][x] = true;
            arrRes[y + 1][x] = dist + 1;
        }
        if (y - 1 >= 0 && !arrVisited[y - 1][x]) {
            qBFS.push({ x, y - 1 });
            arrVisited[y - 1][x] = true;
            arrRes[y - 1][x] = dist + 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arrRes[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}