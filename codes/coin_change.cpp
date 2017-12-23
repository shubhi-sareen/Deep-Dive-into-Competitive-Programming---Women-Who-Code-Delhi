#include <iostream>
#include <climits>
using namespace std;

int num_coins_rec (int N, int C[100], int m) {

    if (N == 0){
        return 0;
    }
    int retval =  INT_MAX;
    for (int i = 0; i < m; i++) {
        if (C[i] <= N){
            retval = min(1+num_coins_rec(N-C[i],C,m), retval);
        }
    }
    return retval;
}

int num_coins_dp (int N, int C[100], int m) {

    int dp[100];

    for (int i = 0; i <= N; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0 ; j < m; j++) {
            if (C[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - C[j]]);
            }
        }
    }

    for(int	i =	1;i<=N;i++)cout<<i<<"	"<<dp[i]<<endl;
    return	dp[N];

}

int main () {

    int N, C[100], m;

    cout << "Enter N: ";
    cin >> N;

    cout << "\nEnter number of coins: ";
    cin >> m;

    cout << "\nEnter coin denominations: ";

    for (int i = 0; i < m; i++) {
        cin >> C[i];
    }

    cout << "\nMinimum coins by recursion: " << num_coins_rec(N,C,m)<<"\n";
    cout << "\nMinimum coins by DP: " << num_coins_dp(N,C,m);
    return 0;
}
