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


void Dfs(vector<int>* graph, bool* visited, int cur, int* num)
{
    for (auto& i : graph[cur])
    {
        if (!visited[i])
        {
            visited[i] = true;
            (*num)++;
            Dfs(graph, visited, i, num);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int iInputN{}, iInputM{};
    int iIterInput{};
    int a{}, b{};


    cin >> iInputN >> iInputM;
    vector<int>* graph; // graph[0] XX
    graph = new vector<int>[iInputN + 1];

    while (iInputM--)
    {
        int u{}, v{};

        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // search
    bool* visited;
    visited = new bool[iInputN + 1];
    memset(visited, false, sizeof(bool) * iInputN + 1);

    int res{};

    for (size_t i = 1; i < iInputN + 1; i++)
    {
        if (visited[i] == false)
        {
            int num{};

            Dfs(graph, visited, i, &num);
            //if (num > 0)
            res++;
        }
    }
    cout << res;

    return 0;
}