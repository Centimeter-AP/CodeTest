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
using lessheap_pq = priority_queue<pii, vector<pii>, greater<pii>>;
constexpr int INF = 1e9; // 10억, inf+inf해도 overflow 안 되는 값으로 


/*
    모든 노드에서 한 위치로 도착하는 경로를 찾을 때
    노드 수 만큼 알고리즘을 돌리는 게 아니라
    그래프 자체를 거꾸로 저장한 다음
    한 위치에서 모든 노드로 다 퍼지는 한번의 알고리즘만 사용해서 구한다
    신기하네요
*/

vector<int> dijk(int start, int N, vector<vector<pii>> graph);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{}, X{};

    cin >> N >> M >> X;
    // 학생 수, 단방향 간선 수, 목적지

    //vector<vector<int>> table(N + 1, vector<int>(N + 1, INF));
    vector<vector<pii>> graph(N + 1, vector<pii>());
    vector<vector<pii>> rev_graph(N + 1, vector<pii>());

    int start{}, end{}, weight{};

    for (int i = 0; i < M; i++)
    {
        cin >> start >> end >> weight;

        graph[start].push_back({ end, weight });
        rev_graph[end].push_back({ start, weight });
    }

    auto dist = dijk(X, N, graph);
    auto rev_dist = dijk(X, N, rev_graph);
    int res{};

    for (int i = 1; i <= N; i++)
    {
        int total_dist = dist[i] + rev_dist[i];
        if (res < total_dist)
            res = total_dist;
    }

    cout << res;

    return 0;
}

vector<int> dijk(int start, int N, vector<vector<pii>> graph)
{
    lessheap_pq pq;
    pq.push({ 0, start });

    vector<int> dist(N + 1, INF);
    dist[start] = 0;

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < weight)
            continue;

        for (auto& next : graph[node])
        {
            if (dist[next.first] > dist[node] + next.second)
            {
                dist[next.first] = dist[node] + next.second;
                pq.push({ next.second, next.first });
            }
        }
    }
    return dist;
}