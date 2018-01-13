#include <iostream>
#include<climits>
using namespace std;

//helper function to sum frequencies from i to j
int sum (int freq[], int i, int j) {
    int retval = 0;
    for (int k = i ; k <= j; k++) {
        retval+=freq[k];
    }
    return retval;
}

int optimalCost (int keys[], int freq[], int n) {

    //cost[i][j] scores the optimal cost for tree formed by nodes from i to j. We have to find cost[0][n-1]
    int cost[n][n];

    //cost of single node is its frequency
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    for (int length = 2; length <=n; length++) {

        //i = row number in cost[][]
        for (int i = 0; i < n-length+1; i++) {

            //Column number j from i and length
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r<=j; r++) {

                int c = ((r > i)? cost[i][r-1]:0) + ((r < j) ? cost[r+1][j]:0) + sum(freq,i,j);

                if (c < cost[i][j]) cost[i][j] = c;
            }

        }
    }

    return cost[0][n-1];
}

int main() {
    int keys[] = {5, 7, 10, 15};
    int freq[] = {1, 10, 8, 9};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<optimalCost(keys, freq, n);
    return 0;
}
