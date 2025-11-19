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

int fibo();

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    }
    else if (n == 1) {
        printf("1");
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


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

    int fibo[41][2];

    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;

    for (size_t i = 0; i < N; i++)
    {
        cin >> M;
        for (size_t i = 2; i <= M; i++)
        {
            fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
            fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
        }
        cout << fibo[M][0] << ' ' << fibo[M][1] << '\n';
    }


    return 0;
}