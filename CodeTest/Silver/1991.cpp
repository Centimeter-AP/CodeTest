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
using pcc = pair<char, char>;
pcc node[27] = {};

void inorder(int idx);
void postorder(int idx);
void preorder(int idx);

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

    for (size_t i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        cin >> node[c - 'A' + 1].first >> node[c - 'A' + 1].second;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);

    return 0;
}

// preorder, inorder, postorder (전위 중위 후위)

void preorder(int idx) // Root - L - R
{
    cout << static_cast<char>(idx + 'A' - 1);

    char left, right;
    left = node[idx].first;
    right = node[idx].second;

    if ('.' != left && '\0' != left)
        preorder(left - 'A' + 1);

    if ('.' != right && '\0' != right)
        preorder(right - 'A' + 1);
}

void inorder(int idx) // L - Root - R
{
    char left, right;
    left = node[idx].first;
    right = node[idx].second;

    if ('.' != left && '\0' != left)
        inorder(left - 'A' + 1);

    cout << static_cast<char>(idx + 'A' - 1);


    if ('.' != right && '\0' != right)
        inorder(right - 'A' + 1);
}

void postorder(int idx) // L - R - Root
{
    char left, right;
    left = node[idx].first;
    right = node[idx].second;

    if ('.' != left && '\0' != left)
        postorder(left - 'A' + 1);

    if ('.' != right && '\0' != right)
        postorder(right - 'A' + 1);

    cout << static_cast<char>(idx + 'A' - 1);
}