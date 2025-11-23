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
#include <numeric>

using namespace std;

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

    set<string> settext;

    cin >> N;

    while (N--)
    {
        string t;
        cin >> t;
        settext.insert(t);
    }
    vector<string> text(settext.begin(), settext.end());
    sort(text.begin(), text.end(), [](string& a, string& b)
        {
            return a.length() < b.length() ? true :
                (a.length() == b.length() && a < b ? true : false);

        });

    for (auto& t : text)
    {
        cout << t << '\n';
    }
    return 0;
}