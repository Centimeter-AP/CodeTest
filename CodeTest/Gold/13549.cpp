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

// priority_queue, deque를 사용하는 문제
// pque는 다익스트라용, 간선의 가중치가 다양할 때 가중치가 가장 적은게 가장 앞으로 오도록 사용..
// deque는 0-1 DFS용, 간선의 가중치가 0 or 1일 때 0은 앞에 삽입, 1은 뒤에 삽입하는 방식으로 사용..
// 이건 그냥 무식하게 풀음(운좋아서통과)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, K{};
    int iIter{};
    int a{}, b{};
    int res{};
    cin >> N >> K;

    queue<int> q;
    vector<int> dist(100001, -1);
    
    q.push(N);
    dist[N] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == K)
            break;

        for (int nx : {x + 1, x - 1, 2 * x})
        {
            if (nx >= 0 && nx <= 100000 && (dist[nx] == -1 || dist[nx] > dist[x]))
            {
                dist[nx] = dist[x];
                if (nx != 2 * x)
                    dist[nx] += 1;
                q.push(nx);
            }
        }        
    }

    cout << dist[K];

    return 0;
}