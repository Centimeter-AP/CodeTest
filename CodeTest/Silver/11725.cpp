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

vector<int> graph[100001];
int res[100001];
bool visited[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N{};

	cin >> N;

	int a{}, b{};

	for (size_t i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> BFS;
	BFS.push(1);
	memset(visited, false, sizeof(bool) * 100001);
	visited[1] = true;

	while (!BFS.empty())
	{
		int idx = BFS.front();
		BFS.pop();
		for (auto& i : graph[idx])
		{
			if (visited[i] == false)
			{
				BFS.push(i);
				res[i] = idx;
				visited[i] = true;
			}
		}
	}

	for (size_t i = 2; i <= N; i++)
	{
		cout << res[i] << '\n';
	}

	return 0;
}