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
//Z

using namespace std;
void Recursive(int row, int col, int N);

int res{};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, r{}, c{};

    cin >> N >> r >> c;

    Recursive(r, c, N);



    cout << res;

    return 0;
}

void Recursive(int row, int col, int N)
{
    if (N == 0)
        return;

    int half{ 1 << (N - 1)}; // 2의 N-1승
    int curBlockSize{ half * half };

    if (row < half && col < half) // 0
    {
        res += 0 * curBlockSize;
        Recursive(row % half, col % half, N - 1);
    }
    else if (row < half && col >= half) // 1
    {
        res += 1 * curBlockSize;
        Recursive(row % half, col % half, N - 1);
    }
    else if (row >= half && col < half) // 2
    {
        res += 2 * curBlockSize;
        Recursive(row % half, col % half, N - 1);
    }
    else if (row >= half && col >= half) // 0
    {
        res += 3 * curBlockSize;
        Recursive(row % half, col % half, N - 1);
    }
}