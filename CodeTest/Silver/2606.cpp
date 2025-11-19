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

int res = -1;

void bfs(vector<int>* PC, bool* visited, queue<int>* nextpc)
{
    int idx = nextpc->front();
    nextpc->pop();
    ++res;
    for (auto& next : PC[idx])
    {
        if (visited[next] == false)
        {
            nextpc->push(next);
            visited[next] = true;
        }
    }
    if (!nextpc->empty())
        bfs(PC, visited, nextpc);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{};
    int iIter{};

    vector<int> PC[101];
    cin >> N >> M;

    // graph
    for (size_t i = 0; i < M; i++)
    {
        int a{}, b{};
        cin >> a >> b;
        PC[a].push_back(b);
        PC[b].push_back(a);
    }
    
    bool visited[101];
    memset(visited, false, sizeof(bool) * 101);
    visited[1] = true;
    queue<int> nextpc;
    nextpc.push(1);
    //bfs
    bfs(PC, visited, &nextpc);




    cout << res;

    return 0;
}