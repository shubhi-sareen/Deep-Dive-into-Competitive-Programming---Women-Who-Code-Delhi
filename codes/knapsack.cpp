#include <iostream>
using namespace std;

int dp[100][100];

int knapsack(int N, int W, int weight[100], int value[100]) {

    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=W; j++){

        //Base case
        //When no object is to be explored or our knapsack's capacity is 0
        if(i == 0 || j == 0)
            dp[i][j] = 0;

        //When the wieght of the item to be considered is more than the
        //knapsack's capacity, we will not include this item
        if(weight[i-1] > j)
            dp[i][j] = dp[i-1][j];
        else
            dp[i][j] = max(value[i-1] + dp[i-1][j - weight[i-1]], dp[i-1][j]);
        }
    }
    return dp[N][W];
}

int main() {

    int N, W, weight[100], value[100];
    cout << "Number of items: ";
    cin >> N;
    cout << "\nKnapsack's Capacity: ";
    cin >> W;
    cout << "\nEnter weight and value:\n";
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    cout << "\nMaximum Value: "<< knapsack(N, W, weight, value);
    return 0;
}
