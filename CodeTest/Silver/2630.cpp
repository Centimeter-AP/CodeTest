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

int paper[128][128];
int white{}, blue{};
//w = 0, b = 1

void recursive(int x, int y, int size);
bool isSame(int x, int y, int size);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.

    int N{}, M{};
    int iIter{};
    int a{}, b{};
    int res{};

    cin >> N;
    int tmp{};
    int input{};
    while (tmp < N * N)
    {
        cin >> input;
        paper[tmp / N][tmp % N] = input;
        tmp++;
    }

    recursive(0, 0, N);

    cout << white << '\n' << blue;

    return 0;
}

void recursive(int x, int y, int size)
{
    if (isSame(x, y, size))
    {
        paper[y][x] == 0 ? white++ : blue++;
        return;
    }
    int half = size / 2;
    if (half < 1)
        return;
    recursive(x, y, half);
    recursive(x + half, y, half);
    recursive(x, y + half, half);
    recursive(x + half, y + half, half);
}

bool isSame(int x, int y, int size)
{
    int first = paper[y][x];
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (paper[i][j] != first)
                return false;
        }
    }
    return true;
}