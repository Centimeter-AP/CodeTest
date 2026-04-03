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
using pii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{};
    int P{}, C{}, W{};

    cin >> N;

    if (N == 1)
    {
        cout << '0';
        return 0;
    }

    vector<vector<pii>> graph(N + 1, vector<pii>());

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> P >> C >> W;
        graph[P].push_back({ C, W });
        graph[C].push_back({ P, W });
    }

    //DFS?BFS?

    stack<pii> DFS;
    vector<int> dist(N + 1, -1);

    DFS.push({ 1,0 });
    dist[1] = 0;

    int iMaxDist = 0;
    int iFar = 1;

    while (!DFS.empty())
    {
        pii node = DFS.top();
        DFS.pop();
        int iCurV = node.first;
        int iCurW = node.second;

        if (iCurW > iMaxDist)
        {
            iMaxDist = dist[iCurV];
            iFar = iCurV;
        }

        for (auto& next : graph[iCurV])
        {
            if (dist[next.first] == -1)
            {
                dist[next.first] = iCurW + next.second;
                DFS.push({ next.first, dist[next.first] });
            }
        }
    }

    fill(dist.begin(), dist.end(), -1);
    iMaxDist = 0;
    DFS.push({iFar, 0});
    dist[iFar] = 0;

    while (!DFS.empty())
    {
        pii node = DFS.top();
        DFS.pop();
        int iCurV = node.first;
        int iCurW = node.second;

        if (iCurW > iMaxDist)
        {
            iMaxDist = dist[iCurV];
            iFar = iCurV;
        }

        for (auto& next : graph[iCurV])
        {
            if (dist[next.first] == -1)
            {
                dist[next.first] = iCurW + next.second;
                DFS.push({ next.first, dist[next.first] });
            }
        }
    }

    cout << iMaxDist << '\n';


    return 0;
}