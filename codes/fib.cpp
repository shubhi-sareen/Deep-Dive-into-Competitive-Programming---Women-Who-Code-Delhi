#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int fib (int n) {
    if (n == 0)
        return 0;
    else if (n==1)
        return 1;

    return fib(n-1) + fib(n-2);
}

int a[100001];

int fib_with_memoization (int n) {

    if (a[n] != -1)
        return a[n];

    if (n == 0) {
        a[0] = 0;
    } else if (n == 1) {
        a[1] = 1;
    } else {
        a[n] = fib_with_memoization(n-1) + fib_with_memoization(n-2);
    }
    return a[n];

}

int dp[100001];

void fib_with_dp() {

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 100001; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
}

int main() {

    int n;
    cin >> n;
    cout << fib(n) << "\n";
    memset(a, -1, 100001);
    cout << fib_with_memoization(n) << "\n";
    fib_with_dp();
    cout << dp[n];
    return 0;

}
