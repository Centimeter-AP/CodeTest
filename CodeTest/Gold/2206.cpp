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

using vvi = vector<vector<int>>;

typedef struct sState
{
    // 현재 위치(x,y), 벽 부쉈는지 여부
    int x, y;
    int broken = 0;
} tState;

int visited[1001][1001][2]={ -1 };
int N{}, M{};

#define UNBROKEN 0
#define BROKEN 1

void BFS(vvi& map);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    memset(visited, -1, sizeof(int) * 1001 * 1001 * 2);
    cin >> N >> M;

    vvi map;

    for (size_t i = 0; i < N; i++)
    {
        vector<int> tmp;
        tmp.reserve(M);
        string s;
        cin >> s;
        for (size_t j = 0; j < M; j++)
        {
            tmp.push_back(s[j] - '0');
        }
        map.push_back(tmp);
    }

    BFS(map);

    return 0;
}

void BFS(vvi& map)
{
    queue<tState> qBFS;
    qBFS.push({ 0,0,0 });
    visited[0][0][0] = 1;
    int dx[4] = { +1, -1, 0, 0 };
    int dy[4] = { 0, 0, +1, -1 };

    while (!qBFS.empty())
    {
        tState front = qBFS.front(); qBFS.pop();
        int x{ front.x }, y{ front.y };
        int a{ front.broken };

        if (x == M-1 && y == N-1)
        {
            cout << visited[y][x][a]; 
            return;
        }

        for (int d = 0; d < 4; d++)
        {
            int nx{ x + dx[d] }, ny{ y + dy[d] };

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (visited[ny][nx][a] != -1) continue;

            if (map[ny][nx] == 1 && a == UNBROKEN)
            {
                qBFS.push({ nx, ny, BROKEN });
                visited[ny][nx][BROKEN] = visited[y][x][a] + 1;
            }
            else if (map[ny][nx] == 0)
            {
                qBFS.push({ nx, ny, a });
                visited[ny][nx][a] = visited[y][x][a] + 1;
            }
        }
    }
    cout << -1;
}