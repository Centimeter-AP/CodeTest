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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{}, V{};
    int iIter{};
    int a{}, b{};
    int res{};

    vector<int> vecGraph[1001];

    cin >> N >> M >> V;
    
    while (M--)
    {
        cin >> a >> b;
        vecGraph[a].push_back(b);
        vecGraph[b].push_back(a);
    }

    queue<int> BFSqueue;
    stack<int> DFSstack;

    BFSqueue.push(V);
    DFSstack.push(V);

    bool visited[1001] = { false, };
    while (!DFSstack.empty())
    {
        int idx = DFSstack.top();
        DFSstack.pop();
        if (visited[idx]) continue;
        cout << idx << " ";
        visited[idx] = true;
        sort(vecGraph[idx].begin(), vecGraph[idx].end(), greater<int>());
        for (auto& node : vecGraph[idx])
        {
            if (!visited[node])
                DFSstack.push(node); // 넣을 때 높은 숫자부터 넣기
        }

    }

    cout << "\n";
    memset(visited, false, sizeof(bool) * 1001);
    visited[V] = true;

    while (!BFSqueue.empty())
    {
        int idx = BFSqueue.front();
        cout << idx << " ";
        BFSqueue.pop();
        sort(vecGraph[idx].begin(), vecGraph[idx].end(), less<int>());
        for (auto& node : vecGraph[idx])
        {
            if (!visited[node])
            {
                BFSqueue.push(node); // 넣을 때 낮은 숫자부터 넣기
                visited[node] = true;
            }
        }

    }

    return 0;
}