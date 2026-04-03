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

    int V{}, E{}, K{};
    int iIter{};
    int a{}, b{};
    int res{};

    cin >> V >> E >> K;
    // 정점의 개수 / 간선의 개수 / 시작 정점 번호

    vector<vector<pii>> graph(V + 1, vector<pii>());

    int src{}, dst{}, w{};

    for (int i = 0; i < E; i++)
    {
        cin >> src >> dst >> w;
        graph[src].push_back({ w, dst });
    }
    constexpr int INF = 1e9; // 10억, inf+inf해도 overflow 안 되는 값으로 
    vector<int> dist(V + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pqDFS;

    pqDFS.push({0, K});
    dist[K] = 0;
    //  가중치, 위치번호


    while (!pqDFS.empty())
    {
        pii node = pqDFS.top();
        pqDFS.pop();
        int iCurW = node.first;
        int iCurV = node.second;

        if (iCurW > dist[iCurV])
            continue;

        for (auto& next : graph[iCurV])
        {
            int iNextW = next.first;
            int iNextV = next.second;

            if (dist[iNextV] > iCurW + iNextW)
            {
                dist[iNextV] = iCurW + iNextW;
                pqDFS.push({ dist[iNextV], iNextV });
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << '\n';
    }

    return 0;
}