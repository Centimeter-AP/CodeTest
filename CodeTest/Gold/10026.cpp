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

int grid[100][100];
int gridAlt[100][100];
bool visited[100][100];
bool visitedAlt[100][100];
int N;
enum color { R = 0, G = 1, B = 2 };
void BFS(int idx, bool Alt);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int iIter{};
    int a{}, b{};
    int res{}, resAlt{};

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            if (s[j] == 'R') {
                gridAlt[i][j] = grid[i][j] = R;
            }
            if (s[j] == 'G') {
                grid[i][j] = G;
                gridAlt[i][j] = R;
            }
            if (s[j] == 'B') {
                gridAlt[i][j] = grid[i][j] = B;
            }
            visited[i][j] = false;
            visitedAlt[i][j] = false;
        }
    }




    for (int i = 0; i < N*N; i++)
    {
        if (visited[i / N][i % N] == false)
        {
            BFS(i, false);
            res++;
        }
        if (visitedAlt[i / N][i % N] == false)
        {
            BFS(i, true);
            resAlt++;
        }
    }



    cout << res << ' ' << resAlt;

    return 0;
}

void BFS(int idx, bool Alt)
{
    stack<int> bstack;
    bstack.push(idx);
    bool (*pVisited)[100][100] = nullptr;
    int (*pGrid)[100][100] = nullptr;

    if (Alt)
    {
        pVisited = &visitedAlt;
        pGrid = &gridAlt;
    }
    else
    {
        pVisited = &visited;
        pGrid = &grid;
    }

    (*pVisited)[idx / N][idx % N] = true;

    //visited[idx / N][idx % N] = true;
    int curColor = (*pGrid)[idx / N][idx % N];
    //int x{ idx % N }, y{ idx / N };

    while (!bstack.empty())
    {
        int curidx{};
        curidx = bstack.top();
        bstack.pop();
        int x{ curidx % N }, y{ curidx / N };

        //if (visited[y][x] == true)
        //    continue;

        if (x + 1 < N && (*pVisited)[y][x + 1] == false && (*pGrid)[y][x + 1] == curColor) {
            bstack.push((x + 1) + y * N); (*pVisited)[y][x + 1] = true;
        }
        if (x - 1 >= 0 && (*pVisited)[y][x - 1] == false && (*pGrid)[y][x - 1] == curColor) {
            bstack.push((x - 1) + y * N); (*pVisited)[y][x - 1] = true;
        }
        if (y + 1 < N && (*pVisited)[y+1][x] == false && (*pGrid)[y + 1][x] == curColor) {
            bstack.push( x + (y+1) * N); (*pVisited)[y + 1][x] = true;
        }
        if (y - 1 >= 0 && (*pVisited)[y-1][x] == false && (*pGrid)[y - 1][x] == curColor) {
            bstack.push(x + (y-1) * N); (*pVisited)[y - 1][x] = true;
        }
    }
}